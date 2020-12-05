#ifndef MAP_H
#define MAP_H

#include <array>
#include <string>
#include "Lib.h"
#include "Grid.h"
#include "WindowInfo.h"

namespace gnGame {

	using std::string;
	using std::array;
	
	// マップの初期の幅と高さ
	namespace MapInfo {
		constexpr int MapWidth  = 60;	       // マップの横の数
		constexpr int MapHeight = 60;	       // マップの縦の数
		constexpr int MapSize   = 32;          // マップのサイズ
		constexpr int MapHSize  = MapSize / 2; // マップの半分のサイズ
	};

	namespace WorldMapSize {
		constexpr int WorldMapWidth  = MapInfo::MapWidth * MapInfo::MapSize;
		constexpr int WorldMapHeight = MapInfo::MapHeight * MapInfo::MapSize;
	}

	// マップのタイル
	enum class MapTile {
		NONE   = -1,
		BLOCK  = 1,
		OBJECT = 2,
	};

	/// <summary>
	/// マップのブロックのオブジェクト
	/// </summary>
	class MapBlock : public Object{
	public:
		MapBlock(MapTile _mapTile)
			: tiletype(_mapTile)
		{}

		MapTile getTileType() {
			return tiletype;
		}

	private:
		MapTile tiletype;
	};

	using MapField = array<array<MapBlock, MapInfo::MapWidth>, MapInfo::MapHeight>;

	/// <summary>
	/// マップクラス
	/// </summary>
	class Map {
	public:
		Map();
		~Map() = default;

		// マップを読み込む
		void loadMapFile(const string& _fileName);

		// マップを描画する
		void drawMap();

		// 値を設定する
		void setTile(int _x, int _y, MapTile _mapInfo);

		// 地面となるタイルか調べる
		bool checkTile(int _x, int _y);

		// 配列内の値を確認する
		MapTile getTile(int _x, int _y);

		// マップをクリアする
		void claerMap();

		// 画面外か判定する
		bool isOnScreen(const Vector2& _pos);

		// マップのサイズを取得する
		Vector2 getMapSize();

	private:
		int mapWidth;
		int mapHeight;
		Grid grid;
		//MapField map;

		// テスト用テクスチャ
		Sprite sprite;
		Sprite sprite2;
	};

};


#endif // !MAP_H
