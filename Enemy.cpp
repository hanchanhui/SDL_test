#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
  SDLGameObject::drawFrame();
}

void Enemy::update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 5;
  SDLGameObject::update();
}

void Enemy::clean()
{
  
}