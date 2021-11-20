#pragma once
#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include "InputHandler.h"


class Game
{
public:
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
  void quit() { m_bRunning = false; }

private:
  Game() {}
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int boxX;

  std::vector<GameObject*> m_gameObjects;
  std::vector<GameObject*> m_wall;

};
typedef Game TheGame;

#endif