#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Wall.h"


Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

    } else return false;
  }
  else
  {
    return false;
  }

  if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
  {
    return false;
  }
  if( !TheTextureManager::Instance()->load("Assets/back.png", "Background", m_pRenderer))
  {
    return false;
  }
  if(!TheTextureManager::Instance()->load("Assets/helicopter.png", "Enemy", m_pRenderer))
  {
    return false;
  }
  if(!TheTextureManager::Instance()->load("Assets/box.png", "box", m_pRenderer))
  {
    return false;
  }
  boxX = 0;
  m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  //m_gameObjects.push_back(new Enemy(new LoaderParams(450, 100, 128, 82, "Enemy")));
  for(int i = 0; i < 20; i++)
  {
      m_wall.push_back(new Wall(new LoaderParams(boxX, 328, 32, 32, "box")));
      m_wall.push_back(new Wall(new LoaderParams(128, 296, 32, 32, "box")));
      boxX += 32;
  }

  m_bRunning = true;
  return true;
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  TheTextureManager::Instance()->draw("Background",0, 0, 640, 360, m_pRenderer);

  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  for(int i = 0; i < m_wall.size(); i++)
  {
    m_wall[i]->draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  for(int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }

  for(int i = 0; i < m_wall.size(); i++)
  {
    m_wall[i]->update();
  }
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}