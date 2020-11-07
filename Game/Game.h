#ifndef GAME_H
#define GAME_H

#include "Lib.h"
#include "Scene.h"
#include "Camera.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

namespace gnGame {

	class Game : public IScene{
	public:
		Game();
		~Game() = default;

		void onStart() override;
		void onUpdate() override;

	private:
		Camera camera;
		Map map;
		Player player;
		Enemy e;
	};
}

#endif // !GAME_H
