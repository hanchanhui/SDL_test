#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 5;
  SDLGameObject::update(1);
}

void Enemy::clean()
{
  
}