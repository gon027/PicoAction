#ifndef BULLET_H
#define BULLET_H

#include "Lib.h"
#include "GameObject.h"
#include "Actor.h"

namespace gnGame {

	class Enemy;
	class Map;
	class Player;

	using EnemyPtr = std::shared_ptr<Enemy>;

	class Actor;
	using ActorPtr = std::shared_ptr<Actor>;

	using PlayerPtr = std::shared_ptr<Player>;


	/// <summary>
	/// 誰が打った弾なのか識別する
	/// </summary>
	enum class BulletType {
		Enemy,   // 敵
		Player,  // プレイヤー
	};

	class Bullet : public GameObject {
	public:
		Bullet(const Vector2& _pos, const Vector2& _velocity, BulletType _bulletType = BulletType::Enemy);
		~Bullet() = default;

		void onStart() override;

		void onUpdate() override;

		void onDraw() override;

		float getAttack();
		void setAttack(float _attack);

		// 敵との当たり判定
		void onCollision(const ActorPtr& _actor);


		/*
		bool intersectMap(Map& _map);
		bool hitEnemy(EnemyPtr& _actor);
		bool hitPlayer(Player& _actor);

		BulletType getBulletType();
		*/

		CircleCollider& getCollider();

	private:
		Sprite bulletImage;
		Vector2 velocity;
		BulletType bulletType;
		float attack;
		CircleCollider collider;
		Bounds bounds;
		IntersectPoint intersectPoint;
	};
}

#endif // !BULLET_H
