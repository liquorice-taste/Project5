#ifndef PROJECT5_TEXTUREMANAGER_H_
#define PROJECT5_TEXTUREMANAGER_H_


#include "SDL.h"
#include "Vector2D.h"

class TextureManager {
 public:
  static SDL_Texture* LoadTexture(const char* file);
  static void DrawTexture(SDL_Texture* Tex, SDL_Rect srcRect, SDL_Rect destRect);
  static void DrawWord(std::string &word, Vector2D vec, SDL_Texture* Tex);
};

#endif  //  PROJECT5_TEXTUREMANAGER_H_

