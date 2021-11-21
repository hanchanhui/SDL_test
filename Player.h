#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Game.h"
#include "Bullet.h"
#include <vector>

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
  void Gravity(float gravity);
  void checkCollision();
  

private:
  bool isGrounded;
  bool Atcount;

};