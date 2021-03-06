#pragma once

#include "SDL.h"

class Check {
  public:
    ~Check() {}
    static Check* Instance() {
      if(s_pInstance == 0) {
        s_pInstance = new Check();
      }
      return s_pInstance;
    }
    // λΉκ΅
    SDL_RendererFlip checkbulflip() { return bulflip; }
    // λμ
    void getbulflip(SDL_RendererFlip a) { bulflip = a;} 
    
  public:
    SDL_RendererFlip bulflip;
    
  private:
    Check(){};
    static Check* s_pInstance; 
};

typedef Check TheCheck;
