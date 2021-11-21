#pragma once
#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include "Player.h"
#include "InputHandler.h"



class Game
{
public:
  Game() {}
  static Game* Instance()
  {
    if (s_pInstance == 0) s_pInstance = new Game();
    return s_pInstance;
  }
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();
  SDL_Renderer* getRenderer() const { return m_pRenderer; }
  std::vector<GameObject*> getWall() const { return m_wall; }
  std::vector<GameObject*> getBullet() const { return m_bulletObjects; }
  template <class T>
  void getBullet(T* t)
  {
    m_bulletObjects.push_back(t);
  }
  

  void quit() { m_bRunning = false; }
  void BulletDestory();

private:
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int boxX;
  

  std::vector<GameObject*> m_gameObjects;
  std::vector<GameObject*> m_bulletObjects;
  std::vector<GameObject*> m_wall;


};
typedef Game TheGame;

#endif