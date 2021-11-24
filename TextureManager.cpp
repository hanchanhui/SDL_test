#include "TextureManager.h"
#include "SDL_image.h"
#include "Camera.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if (pTempSurface == 0) return false;

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if (pTexture != 0)
  {
    m_textureMap[id] = pTexture;
    return true;
  }

  return false;
}

void TextureManager::Textload(int x, int y, SDL_Renderer* pRenderer)
{
  SDL_Color color = {255, 255, 255};
  TTF_Font* font = TTF_OpenFont("Assets/arial.ttf", 25);
  TTF_CloseFont(font);
  SDL_Surface* surface = TTF_RenderText_Blended(font, "Hello", color);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect r = {0, 0, surface->w, surface->h}; 
  SDL_RenderCopyEx(pRenderer, texture, 0, &r, 0, 0, SDL_FLIP_NONE);

}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x - TheCamera::Instance()->getCameraRect().x;
  destRect.y = y - TheCamera::Instance()->getCameraRect().y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * currentRow;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x - TheCamera::Instance()->getCameraRect().x;
  destRect.y = y - TheCamera::Instance()->getCameraRect().y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
