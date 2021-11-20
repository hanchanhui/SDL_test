#pragma once
#include "SDLGameObject.h"

class Wall : public SDLGameObject
{
public:
  Wall(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();


public:

  Vector2D GetPosition() const { return m_position; }


};