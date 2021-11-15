#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::init(){
  m_Num = 0;
  jumcount = 0;
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
  SDLGameObject::m_currentFrame = (SDL_GetTicks() / 100) % 6;
  SDLGameObject::update(4);
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(4);
    m_Num = 1;
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-4);
    m_Num = 2;
  }
  else{
    m_velocity.setX(0);
  }
  
  
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    if(m_position.getY() > 220 && jumcount == 1){
      m_acceleration.setY(-7);
      jumcount = 0;
    }else if(m_position.getY() <= 220 && jumcount == 1){
      m_acceleration.setY(-2);
    }
  }
  if(m_position.getY() > 287 ){
    m_velocity.setY(0);
    jumcount = 1;
  }
  if( m_position.getY() <= 180)
  {
    m_acceleration.setY(0);
  }
}

void Player::Collider()
{
  
}

void Player::clean()
{
  
}