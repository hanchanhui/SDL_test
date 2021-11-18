#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
  virtual void draw() {};
  virtual void update() {};
  virtual void clean() {};
  virtual ~GameObject() {}
  

public:
  GameObject(const LoaderParams* pParams) 
  {
      m_x = pParams->getX();
      m_y = pParams->getY();
      m_width = pParams->getWidth();
      m_height = pParams->getHeight();
  }

  int m_x;
  int m_y;
  int m_width;
  int m_height;
  

};