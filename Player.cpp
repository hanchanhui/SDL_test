#include "Player.h"
#include "Check.h"
#include "Camera.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) , isGrounded(false), isFire(false) , plyDir(true), ground(0){}


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
  CameraMove();
  SDLGameObject::update();
}



void Player::handleInput()
{
  //좌우 키
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    flip = SDL_FLIP_NONE;
    m_velocity.setX(2);
    plyDir = true;
    ground += 1;
    if(!TheGame::Instance()->getFire()){
      TheCheck::Instance()->getbulflip(SDLGameObject::flip);
    }
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    flip = SDL_FLIP_HORIZONTAL;
    m_velocity.setX(-2);
    plyDir = false;
    ground -= 1;
    if(!TheGame::Instance()->getFire()){
      TheCheck::Instance()->getbulflip(SDLGameObject::flip);
    }
  }
  else{
    m_velocity.setX(0);
  }
  // 점프
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
  {
    if(isGrounded){
      m_velocity.setY(-10);
      Gravity(2.5);
      isGrounded = false;
    }
  }
  // 공격
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && !TheGame::Instance()->getFire())
  {
    isFire = true;
    TheGame::Instance()->Firecheck(isFire);
    
    if(plyDir){
      Bullet* bullet = new Bullet(new LoaderParams(m_position.getX() + m_width - 30,   m_position.getY() + 15, 32, 32, "bullet"));
      TheGame::Instance()->getBullet(bullet);
    }
    if(!plyDir)
    {
      Bullet* bullet = new Bullet(new LoaderParams(m_position.getX(), m_position.getY() + 15, 32, 32, "bullet"));
      TheGame::Instance()->getBullet(bullet);
    }

  }
  
  
  TheCamera::Instance()->getCameraRectX((m_position.getX() + (m_width / 2)) - 320);
  TheCamera::Instance()->getCameraRectY((m_position.getY() + (m_height / 2)) - 250);

  
  if(TheCamera::Instance()->getCameraRect().x < 0){
    TheCamera::Instance()->getCameraRectX(0);
  }
  if(TheCamera::Instance()->getCameraRect().y < 0){
    TheCamera::Instance()->getCameraRectY(0);
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
        m_position.setX(wallLeft - m_width + 30);
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

void Player::CameraMove()
{
  TheGame::Instance()->getCamRectX(m_position.getX() - (m_width / 2) - TheCamera::Instance()->getCameraRect().x);
  TheGame::Instance()->getCamRectY(m_position.getY() - (m_height / 2) - TheCamera::Instance()->getCameraRect().y);
}

void Player::clean()
{
  
}