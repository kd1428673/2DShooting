#pragma once
class C_Enemy
{
public:

	C_Enemy();
	~C_Enemy();

	void Init();
	void Update();
	void Draw();
	void Hit();

	void SetTex(KdTexture* tex);

	bool GetAlive();
	Math::Vector2 Getpos();
	float GetRadius();


private:

	const float m_enemyMoveSpeed = 5.0f;
	const float m_radius = 32.0f;

	KdTexture* m_enemyTex;
	Math::Vector2 m_enemyPos;//À•W
	Math::Vector2 m_enemyMove;//ˆÚ“®—Ê
	Math::Matrix m_enemyMat;
	bool m_alive;
};

