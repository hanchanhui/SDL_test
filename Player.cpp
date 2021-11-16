#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {
  
}

void Player::init(){
  m_Num = 0;
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
  SDLGameObject::update();
  

  handleInput();
  m_currentFrame = (SDL_GetTicks() / 100) % 6;
  
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(2);
    SDLGameObject::draw();
    m_Num = 1;
  }
  else{
    m_velocity.setX(0);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-2);
    SDLGameObject::drawDir();
    m_Num = 2;
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    m_velocity.setY(-4);
  }else if(m_position.getY() > 290){
    m_velocity.setY(0);
  }
  
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
    m_velocity.setY(2);
  }

  
}

void Player::clean()
{
  
}