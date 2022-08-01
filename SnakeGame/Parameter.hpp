#pragma once

class Parameter {
public:
	/// マスの大きさ
	static const int GridSize = 10;
	/// グリッドの間隔
	static const int GridSpace = 2;
	/// ステージの高さ
	static const int StageHeight = 20;
	/// ステージの幅
	static const int StageWidth = 20;
	/// 何fpsごとにターンを更新するか
	static const int TurnSpace = 10;

	/// Fruitのシード値
	static const unsigned int FruitSeed = 0x12345679;
};