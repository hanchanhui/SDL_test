#include "SDLGameObject.h"
#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_acceleration(0,0), m_Force(0,0), m_Friction(0,0)
{
  m_x = pParams->getX();
  m_y = pParams->getY();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureID = pParams->getTextureID();
  m_currentRow = 0;
  m_currentFrame = 0;
  m_Mass = UNI_MASS;
  m_Gravity = GRAVITY;
}

void SDLGameObject::draw()
{
  TheTextureManager::Instance()->drawFrame(m_textureID, (int) m_position.getX(), (int) m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::drawDir()
{
  TheTextureManager::Instance()->drawFrameDir(m_textureID, (int) m_position.getX(), (int) m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}


void SDLGameObject::update(float dt)
{
  //m_velocity += m_acceleration;
  //m_position += m_velocity;
  
  m_acceleration.m_x = (m_Force.m_x + m_Friction.m_x) / m_Mass;
  m_acceleration.m_y = m_Gravity + m_Force.m_y/m_Mass;
  m_velocity = m_acceleration * dt;
  m_position = m_velocity * dt;
}

void SDLGameObject::clean()
{
  
}