#pragma once

#include "SDL.h"
#include <string>
#include <map>
#include "SDL_ttf.h"

class TextureManager
{
public:
  static TextureManager* Instance()
  {
    if (s_pInstance == 0) s_pInstance = new TextureManager();
    return s_pInstance;
  }
  ~TextureManager() {}

  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

  void Textload(int x, int y, SDL_Renderer* pRenderer);

  void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip);

  void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip);


private:
  TextureManager() : mTexture(NULL) {}
  static TextureManager* s_pInstance;
  std::map<std::string, SDL_Texture*> m_textureMap;

  SDL_Texture* mTexture;
  
};
typedef TextureManager TheTextureManager;