#include "../include/EnemyState.h"
#include "../include/Camera.h"
#include "../include/Bullet.h"
#include "../include/TextureManager.h"
#include "../include/BulletManager.h"

namespace gnGame {
	namespace EnemyState {

		namespace Move {

			// ���������߂�
			Vector2 getDirection(Direction _dir) {
				switch (_dir)
				{
				case Direction::Up:    return Vector2::Up;
				case Direction::Down:  return Vector2::Down;
				case Direction::Left:  return Vector2::Left;
				case Direction::Right: return Vector2::Right;
				default:               return Vector2::Zero;
				}
			}

			EnemyMove::EnemyMove(Enemy* _enemyPtr)
				: enemyPtr(_enemyPtr)
				, velocity()
			{
			}

			void EnemyMove::execute()
			{
				velocity.setPos(getDirection(enemyPtr->getDir()));
				velocity.x *= 2.0f;
				velocity.y = 1.0f;
			}

		}
	}

	namespace EnemyState {

		namespace Attack {

			namespace {
				constexpr float SHOTINTERVAL = 1.0f;
			}

			EnemyAttack::EnemyAttack(Enemy* _enemyPtr)
				: enemyPtr(_enemyPtr)
				, shotTime(0.0f)
			{
			}

			void EnemyAttack::execute()
			{
				shotTime += Time::deltaTime();

				// 1�b��1��ł�
				if (shotTime >= SHOTINTERVAL) {
					if (enemyPtr->getDir() == Direction::Left) {
						BulletPtr bulletPtr(new Bullet(enemyPtr->transform.pos, Vector2{ -10.0f, 0.0f }));
						bulletPtr->onStart();
						BulletManager::getIns()->addBullet(bulletPtr);
					}
					else if (enemyPtr->getDir() == Direction::Right) {
						BulletPtr bulletPtr(new Bullet(enemyPtr->transform.pos, Vector2{ 10.0f, 0.0f }));
						bulletPtr->onStart();
						BulletManager::getIns()->addBullet(bulletPtr);
					}
					shotTime = 0;
				}
			}

		}
	}
}
