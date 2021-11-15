#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "SDL.h"


class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
  void init();
  int m_Num;


};