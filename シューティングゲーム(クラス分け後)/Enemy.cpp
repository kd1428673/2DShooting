#include"Enemy.h"

C_Enemy::C_Enemy()
{

}

C_Enemy::~C_Enemy()
{

}

void C_Enemy::Init()
{
	m_enemyPos.x = 0;
	m_enemyPos.y = 250;
	m_enemyMove.x = m_enemyMoveSpeed;
	m_enemyMove.y = 0;
	m_alive = true;
}

void C_Enemy::Update()
{

	if (!m_alive)return;

	m_enemyPos.x += m_enemyMove.x;

	if (m_enemyPos.x < -608 || m_enemyPos.x > 608)
	{
		m_enemyMove.x *= -1;
	}
	
	m_enemyMat = Math::Matrix::CreateTranslation(m_enemyPos.x, m_enemyPos.y, 0);
}

void C_Enemy::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_enemyMat);
	SHADER.m_spriteShader.DrawTex(m_enemyTex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void C_Enemy::Hit()
{
	m_alive = false;
}

bool C_Enemy::GetAlive()
{
	return m_alive;
}

float C_Enemy::GetRadius()
{
	return m_radius;
}


Math::Vector2 C_Enemy::Getpos()
{
	return m_enemyPos;
}

void C_Enemy::SetTex(KdTexture* tex)
{
	m_enemyTex = tex;
}
