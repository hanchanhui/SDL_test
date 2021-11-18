#include "Player.h"

Player* Player::s_pInstance = 0;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)  {
  
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
  move(TheGame::Instance()->getEnemyObject());
  
  handleInput();
  m_currentFrame = (SDL_GetTicks() / 100) % 6;
  
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(2);
    SDLGameObject::draw();
    mCollider.x = m_position.getX();
    m_Num = 1;
  }
  else{
    m_velocity.setX(0);
  }

  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-2);
    SDLGameObject::drawDir();
    mCollider.x = m_position.getX();
    m_Num = 2;
  }

  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    m_velocity.setY(-4);
    mCollider.y = m_position.getY();
  }else if(m_position.getY() > 290){
    m_velocity.setY(0);
    mCollider.y = m_position.getY();
  }
  
}

void Player::move(std::vector<GameObject*> collider)
{
  if( m_position.getX() < 0 || checkCollision(TheGame::Instance()->getGameObject(), collider))
  {
      m_velocity.setX(0);
  }
}

bool Player::checkCollision(std::vector<GameObject*> a, std::vector<GameObject*> b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    for( int Abox = 0; Abox < a.size(); Abox++){
      leftA = dynamic_cast<SDLGameObject*>(a)->GetPos().getX();
      rightA = a[Abox]->m_x + a[Abox]->m_width;
      topA = a[Abox]->m_y;
      bottomA = a[Abox]->m_y + a[Abox]->m_height;

      for( int Bbox = 0; Bbox < b.size(); Bbox++)
      {
        leftB = b[Bbox]->m_x;
        rightB = b[Bbox]->m_x + a[Bbox]->m_width;
        topB = b[Bbox]->m_y;
        bottomB = b[Bbox]->m_y + a[Bbox]->m_height;

      }
    }
  if(bottomA <= topB)
  {
    return false;
  }

  if(topA >= bottomB){
    return false;
  }

  if(rightA <= leftB)
  {
    return false;
  }

  if(leftA >= rightB)
  {
    return false;
  }

  return true;
    
}

void Player::clean()
{
  
}