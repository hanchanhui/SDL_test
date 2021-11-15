#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams), enemyDir(pParams) {}

void Player::init(){
  m_Num = 0;
  jumcount = 0;
  player.x = m_position.getX();
  player.y = m_position.getY();
  player.w = 128;
  player.h = 82;
}


void Player::draw()
{
  if(m_Num == 0){
    SDLGameObject::draw();
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    SDLGameObject::drawFrame();
  }else if(m_Num == 1){
    SDLGameObject::draw();
  }
  else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    SDLGameObject::drawFrameDir();
  }else if(m_Num == 2){
    SDLGameObject::drawDir();
  }
}

void Player::update()
{
  handleInput();
  Collider(player, enemyDir.enemy);
  SDLGameObject::m_currentFrame = (SDL_GetTicks() / 100) % 6;
  SDLGameObject::update(4);
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(4);
    player.x = m_position.getX();
    m_Num = 1;
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-4);
    player.x = m_position.getX();
    m_Num = 2;
  }
  else{
    m_velocity.setX(0);
  }
  
  
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    if(m_position.getY() > 220 && jumcount == 1){
      m_acceleration.setY(-7);
      player.y = m_position.getY();
      jumcount = 0;
    }else if(m_position.getY() <= 220 && jumcount == 1){
      m_acceleration.setY(-2);
      player.y = m_position.getY();
    }
  }
  if(m_position.getY() > 287 ){
    m_velocity.setY(0);
    player.y = m_position.getY();
    jumcount = 1;
  }
  if(m_position.getY() <= 180)
  {
    m_acceleration.setY(0);
    player.y = m_position.getY();
  }  

}

void Player::Collider(SDL_Rect a, SDL_Rect b)
{
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  leftA = a.x;
  rightA = a.x - a.w;
  topA = a.y;
  bottomA = a.y - a.h;

  leftB = b.x;
  rightB = b.x - b.w;
  topB = b.y;
  bottomB = b.y - b.h;
  
  if( (rightA >= leftB)){
    m_velocity.setX(0);
  }/*
  if(topA >= topB){
    m_velocity.setY(0);
  }*/
  
  
  
  
}

void Player::clean()
{
  
}