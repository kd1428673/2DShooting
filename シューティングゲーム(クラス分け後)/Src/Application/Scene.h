#pragma once
#include"Player.h"
#include"Enemy.h"
class Scene
{
private:
	
	C_Player m_player;//クラスの変数
	C_Enemy m_enemy;//クラスの変数

	KdTexture m_playerTex;
	KdTexture m_enemyTex;

	POINT m_mousePos;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	void  CalcMousePos();

	C_Enemy* GetEnemy();

	int m_h;

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
