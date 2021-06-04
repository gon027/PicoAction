#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "gnLib.h"

namespace gnLib {

	class GameObject : public Object {
	public:
		GameObject() : Object() {}
		virtual ~GameObject() = default;

		// 最初に呼ばれる関数
		virtual void onStart() = 0;

		// 更新時に呼ばれる関数
		virtual void onUpdate() = 0;

		// 描画関数
		virtual void onDraw() = 0;
	};

}

#endif // !GAMEOBJECT_H
