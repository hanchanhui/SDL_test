#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Enemy.h"
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
  void Collider(SDL_Rect a, SDL_Rect b);
  SDL_Rect player;

private:
  int m_Num;
  int jumcount;

  Enemy enemyDir;
};