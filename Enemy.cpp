#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::init()
{
  enemy.x = m_position.getX();
  enemy.y = m_position.getY();
  enemy.w = 128;
  enemy.h = 82;
}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 5;
  SDLGameObject::update();
  if(m_position.getY() >= 280){
    m_velocity.setY(0);
  }
}

void Enemy::clean()
{
  
}