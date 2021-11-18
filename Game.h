#pragma once
#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include "InputHandler.h"

static const int Game_WIDTH = 640;
static const int Game_HEIGHT = 360;

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
  std::vector<GameObject*> getGameObject() const { return m_gameObjects; }
  std::vector<GameObject*> getEnemyObject() const { return m_enemyObjects; }
  void quit() { m_bRunning = false; }

private:
  Game() {}
  static Game* s_pInstance;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  std::vector<GameObject*> m_gameObjects;
  std::vector<GameObject*> m_enemyObjects;
};
typedef Game TheGame;

#endif