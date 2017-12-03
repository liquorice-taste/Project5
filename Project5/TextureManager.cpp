#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char* file) {
  SDL_Surface* Surf = IMG_Load(file);
  SDL_SetColorKey(Surf, SDL_TRUE, SDL_MapRGB(Surf->format, 255, 0, 255));  // 255, 0, 255 - Magenta background color
  SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::Renderer, Surf);
  SDL_FreeSurface(Surf);
  return Tex;
}

void TextureManager::DrawTexture(SDL_Texture * Tex, SDL_Rect srcRect, SDL_Rect destRect) {
  SDL_RenderCopy(Game::Renderer, Tex, &srcRect, &destRect);
}

void TextureManager::DrawWord(std::string &word, Vector2D vec, SDL_Texture * Tex) {
  SDL_Rect srcRect, destRect;
  destRect.x = vec.x;
  destRect.y = vec.y;
  for (int i = 0; i < word.length(); i++) {
    
    srcRect.x = static_cast<int>(word[i] - 65)*24;
    srcRect.y = 0;
    srcRect.h = srcRect.w = 24;
    destRect.h = destRect.w = 50;
    TextureManager::DrawTexture(Tex, srcRect, destRect);
    destRect.x +=50;
  }
}
