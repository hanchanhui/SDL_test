#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void drawDir();
  virtual void drawFrame();
  virtual void drawFrameDir();
  virtual void update(float dt);
  virtual void clean();
  virtual ~SDLGameObject() {}

protected:
  std::string m_textureID;

  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
};
