#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Bullet::draw()
{
  SDLGameObject::flip = SDL_FLIP_NONE;
  SDLGameObject::draw();
}

void Bullet::update()
{
  m_acceleration.setY(0);
  m_velocity.setX(1);
  BulletCollision();
  SDLGameObject::update();
}

void Bullet::BulletCollision()
{
  std::vector<GameObject*> collWall = TheGame::Instance()->getWall();

  int bulLeft = m_position.getX();
  int bulRight = bulLeft + m_width;
  int bulTop = m_position.getY();
  int bulBottom = bulTop + m_height;

  for(int i = 0; i < collWall.size(); i++)
  {
    int wallLeft = dynamic_cast<SDLGameObject*>(collWall[i])->GetPos().getX() ;
    int wallRight = wallLeft + dynamic_cast<SDLGameObject*>(collWall[i])->GetWidth();
    int wallTop = dynamic_cast<SDLGameObject*>(collWall[i])->GetPos().getY();
    int wallBottom = wallTop + dynamic_cast<SDLGameObject*>(collWall[i])->GetHeight();

    if(bulLeft <= wallRight && bulRight >= wallLeft && bulTop <= wallBottom 
        && bulBottom >= wallTop)
    {
      // 아랫방향
      if(m_velocity.getY() > 0 && bulBottom >= wallTop && bulBottom < wallBottom 
          && bulLeft != wallRight && bulRight != wallLeft)
      {
        m_position.setY(wallTop - m_height);
        bulTop = m_position.getY();
        bulBottom = bulTop + m_height;
        
        //m_velocity.setY(0);
      }
      // 윗방향
      else if(m_velocity.getY() < 0 && bulTop <= wallBottom && bulTop > wallTop 
          && bulLeft != wallRight && bulRight != wallLeft)
      {
        m_position.setY(wallBottom);
        bulTop = m_position.getY();
        bulBottom = bulTop + m_height;

        //m_velocity.setY(0);
      }
      // 왼방향
      if(m_velocity.getX() < 0 && bulLeft <= wallRight && bulLeft > wallLeft 
          && bulTop != wallBottom && bulBottom != wallTop)
      {
          m_position.setX(wallRight);
          m_velocity.setX(0);
         TheGame::Instance()->BulletDestory();
      }
      // 오른방향
      else if(m_velocity.getX() > 0 && bulRight >= wallLeft && bulRight < wallRight 
        && bulTop != wallBottom && bulBottom != wallTop)
      {
        m_position.setX(wallLeft - m_width);
        m_velocity.setX(0);
        TheGame::Instance()->BulletDestory();
      }
    }
    
  }

}


void Bullet::clean()
{
  
}