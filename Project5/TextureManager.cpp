#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* Ren) {
	SDL_Texture* Tex = IMG_LoadTexture(Ren, file);
	return Tex;
};