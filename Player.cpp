#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}



void Player::draw()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    SDLGameObject::drawFrame();
  }else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    SDLGameObject::drawFrame();
  }else{
    SDLGameObject::draw();
  }
}

void Player::update()
{
  m_currentFrame = (SDL_GetTicks() / 100) % 6;

  handleInput();
  checkCollision();
  SDLGameObject::update();
}

void Player::handleInput()
{
  //좌우 키
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    SDLGameObject::flip = SDL_FLIP_NONE;
    m_velocity.setX(2);
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    SDLGameObject::flip = SDL_FLIP_HORIZONTAL;
    m_velocity.setX(-2);
  }
  else{
    m_velocity.setX(0);
  }
  // 점프
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
  {
    if(isGrounded){
      m_velocity.setY(-10);
      Gravity(2.5);
      isGrounded = false;
    }
  }
  // 공격
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL))
  {
    
  }

}

void Player::checkCollision()
{
  std::vector<GameObject*> collWall = TheGame::Instance()->getWall();

  int plyLeft = m_position.getX();
  int plyRight = plyLeft + m_width;
  int plyTop = m_position.getY();
  int plyBottom = plyTop + m_height;

  for(int i = 0; i < collWall.size(); i++)
  {
    int wallLeft = dynamic_cast<SDLGameObject*>(collWall[i])->GetPos().getX() ;
    int wallRight = wallLeft + dynamic_cast<SDLGameObject*>(collWall[i])->GetWidth();
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
        isGrounded = true; // 바닥 인식
      }
      // 윗방향
      else if(m_velocity.getY() < 0 && plyTop <= wallBottom && plyTop > wallTop 
          && plyLeft != wallRight && plyRight != wallLeft)
      {
        m_position.setY(wallBottom - 25);
        plyTop = m_position.getY();
        plyBottom = plyTop + m_height;

        m_velocity.setY(0);
      }
      // 왼방향
      if(m_velocity.getX() < 0 && plyLeft <= wallRight && plyLeft > wallLeft 
          && plyTop != wallBottom && plyBottom != wallTop)
      {
          m_position.setX(wallRight - 20);
          m_velocity.setX(0);
      }
      // 오른방향
      else if(m_velocity.getX() > 0 && plyRight >= wallLeft && plyRight < wallRight 
        && plyTop != wallBottom && plyBottom != wallTop)
      {
        m_position.setX(wallLeft - m_width + 20);
        m_velocity.setX(0);
      }
    }
    
  }
  if(m_position.getY() > 300){ // 맵 밖을 이탈하면 점프를 할 수 없이 떨어지는 형식
    isGrounded = false;
  }

}

void Player::Gravity(float gravity)
{
  m_acceleration.setY(gravity);
}

void Player::clean()
{
  
}