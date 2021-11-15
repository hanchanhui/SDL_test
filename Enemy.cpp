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
  if(m_position.getY() >= 278.5){
    m_velocity.setY(0);
  }
  SDLGameObject::update(4);
}

void Enemy::clean()
{
  
}