#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Wall::draw()
{
  SDLGameObject::drawWall();
}

void Wall::update()
{
  
}

void Wall::clean()
{
  
}