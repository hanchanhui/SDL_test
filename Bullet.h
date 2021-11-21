#pragma once
#include "SDLGameObject.h"
#include "Game.h"
#include "SDL.h"
#include <vector>

class Bullet : public SDLGameObject
{
public:
  Bullet(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void BulletCollision();
  void Destory();
  void bulflipDir();

public:
  SDL_RendererFlip bulflip;
  bool setFire;
  
};