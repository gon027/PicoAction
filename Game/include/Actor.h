#ifndef ACTOR_H
#define ACTOR_H

#include "Lib.h"

namespace gnGame {

	struct IntersectPoint {
		static const int Size = 2;

		vector<Vector2> right;
		vector<Vector2> left;
		vector<Vector2> top;
		vector<Vector2> bottom;

		IntersectPoint()
			: right(Size)
			, left(Size)
			, top(Size)
			, bottom(Size)
		{}
	};

	// キャラクターの基底クラス
	class IActor : public Object {
	public:
		IActor() 
			: pos()
			, velocity()
			, bounds()
			, intersectPoint()
		{}

		~IActor() = default;

		virtual void onStart() = 0;
		virtual void onUpdate(float _deltaTime) = 0;

		// マップとの当たり判定
		virtual Vector2 intersectTileMap() = 0;

		inline const Vector2& getPos() {
			return pos;
		}

		inline const Vector2& getVelocity() {
			return velocity;
		}

	protected:
		Vector2 pos;                     // 座標
		Vector2 velocity;                // 速度
		Bounds bounds;                   // バウンディングボックス
		IntersectPoint intersectPoint;   // 床との当たり判定
	};

}

#endif // !ACTOR_H
