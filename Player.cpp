#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::init(){
  m_Num = 0;
  JumpCount = 0;
}

void Player::draw()
{
  if(m_Num == 0){
    SDLGameObject::draw();
  }
  else if(m_Num == 1){
    SDLGameObject::draw();
  }else if (m_Num == 2){
    SDLGameObject::drawDir();
  }
}

void Player::update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 6;

  handleInput();
  Gravity(0.1);
  checkCollision();
  SDLGameObject::update();
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(2);
    SDLGameObject::draw();
    m_Num = 1;
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-2);
    SDLGameObject::drawDir();
    m_Num = 2;
  }
  else{
    m_velocity.setX(0);
  }
  
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
  {
    if((JumpCount == 1) && (m_position.getY() < m_position.getY() + 30)){
      m_velocity.setY(-4);
      Gravity(0.1);
      JumpCount = 0;
    }
  }

}

void Player::checkCollision()
{
  std::vector<GameObject*> collWall = TheGame::Instance()->getWall();

  int plyLeft = m_position.getX();
  int plyRight = plyLeft + m_width - 10;
  int plyTop = m_position.getY();
  int plyBottom = plyTop + m_height;

  for(int i = 0; i < collWall.size(); i++)
  {
    int wallLeft = dynamic_cast<SDLGameObject*>(collWall[i])->GetPos().getX() + 10;
    int wallRight = wallLeft + dynamic_cast<SDLGameObject*>(collWall[i])->GetWidth() - 25;
    int wallTop = dynamic_cast<SDLGameObject*>(collWall[i])->GetPos().getY() + 10;
    int wallBottom = wallTop + dynamic_cast<SDLGameObject*>(collWall[i])->GetHeight();

    if(plyLeft <= wallRight && plyRight >= wallLeft && plyTop <= wallBottom 
        && plyBottom >= wallTop)
    {
      // 아랫방향
      if(m_velocity.getY() > 0 && plyBottom >= wallTop && plyBottom < wallBottom 
          && plyLeft != wallRight && plyRight != wallLeft)
      {
        m_position.setY(wallTop - m_height);
        plyTop = m_position.getY();
        plyBottom = plyTop + m_height;

        m_velocity.setY(0);
        Gravity(0.0);
        JumpCount = 1;
      }
      // 윗방향
      else if(m_velocity.getY() < 0 && plyTop <= wallBottom && plyTop > wallTop 
          && plyLeft != wallRight && plyRight != wallLeft)
      {
        m_position.setY(wallBottom);
        plyTop = m_position.getY();
        plyBottom = plyTop + m_height;

        m_velocity.setY(0);
      }
      // 왼방향
      if(m_velocity.getX() < 0 && plyLeft <= wallRight && plyLeft > wallLeft 
          && plyTop != wallBottom && plyBottom != wallTop)
      {
          m_position.setX(wallRight);
          m_velocity.setX(0);
      }
      // 오른방향
      else if(m_velocity.getX() > 0 && plyRight >= wallLeft && plyRight < wallRight 
        && plyTop != wallBottom && plyBottom != wallTop)
      {
        m_position.setX(wallLeft - m_width);
        m_velocity.setX(0);
      }
    }
    
  }

}

void Player::Gravity(float gravity)
{
  m_acceleration.setY(gravity);
}

void Player::clean()
{
  
}