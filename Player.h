#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "SDL.h"
#include <vector>


class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
  void init();
  void move(std::vector<GameObject*> collider);
  bool checkCollision(std::vector<GameObject*> a, std::vector<GameObject*> b);


private:
  
  int m_Num;
  static Player* s_pInstance;
  SDL_Rect mCollider;

};

