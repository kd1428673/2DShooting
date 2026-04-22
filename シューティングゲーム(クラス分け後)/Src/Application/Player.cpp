#include "Player.h"
#include "Scene.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{

	m_bulletTex.Release();
}

void C_Player::Init()
{
	m_playerPos.x = 0;
	m_playerPos.y = 0;

	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bulletTex.Load("Texture/bullet.png");
		m_bullet[i].SetTex(&m_bulletTex);
		m_bullet[i].Init();
	}
}

void C_Player::Update(POINT mousePos)
{
	if (GetAsyncKeyState('W') & 0x8000)m_playerPos.y += m_playerMoveSpeed;
	if (GetAsyncKeyState('S') & 0x8000)m_playerPos.y -= m_playerMoveSpeed;
	if (GetAsyncKeyState('A') & 0x8000)m_playerPos.x -= m_playerMoveSpeed;
	if (GetAsyncKeyState('D') & 0x8000)m_playerPos.x += m_playerMoveSpeed;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		for (int i = 0; i < m_bulletNum; i++)
		{
			if (!m_bullet[i].GetAlive())
			{
				const float x = mousePos.x - m_playerPos.x;
				const float y = mousePos.y - m_playerPos.y;
				const float radian = atan2(y, x);

				m_bullet[i].Shot(m_playerPos, radian);
				break;
			}
		}
	}

	m_playerMat = Math::Matrix::CreateTranslation(m_playerPos.x, m_playerPos.y, 0);

	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bullet[i].Update();
	}
}

void C_Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_playerMat);
	SHADER.m_spriteShader.DrawTex(m_playerTex, Math::Rectangle(0, 0, 64, 64), 1.0f);

	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bullet[i].Draw();
	}
}

void C_Player::HitBUlletEenemy()
{
	C_Enemy* enemy = m_owner->GetEnemy();
	if (!enemy->GetAlive())return;

	for (int i = 0; i < m_bulletNum; i++)
	{
		if (m_bullet[i].GetAlive())
		{
			const float dx = enemy->Getpos().x - m_bullet[i].Getpos().x;
			const float dy = enemy->Getpos().y - m_bullet[i].Getpos().y;
			const float dist = sqrtf(dx * dx + dy * dy);
			if (dist < (enemy->GetRadius() + m_bullet[i].GetRadius()))
			{
				enemy->Hit();
				m_bullet[i].Hit();
				break;
			}
		}
	}
}

void C_Player::SetTex(KdTexture* tex)
{
	m_playerTex = tex;
}

void C_Player::SetOwner(Scene* owner)
{
	m_owner = owner;
}
