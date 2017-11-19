#include "GameCharacter.h"
#include "TextureManager.h"

GameCharacter::GameCharacter(const char* texturesheet, SDL_Renderer* Ren, int x, int y)
{
	chRen = Ren;
	chTex = TextureManager::LoadTexture(texturesheet, chRen);

	coord_x = x;
	coord_y = y;
}


void GameCharacter::Update()
{
	srcRect.h = 100;
	srcRect.w = 100;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	destRect.x = coord_x;
	destRect.y = coord_y;
	
}

void GameCharacter::Render()
{
	SDL_RenderClear(chRen);
	SDL_RenderCopy(chRen, chTex, &srcRect, &destRect);
	SDL_RenderPresent(chRen);
}

int GameCharacter::getx()
{
	return coord_x;
}

int GameCharacter::gety()
{
	return coord_y;
}

direction GameCharacter::getdirection()
{
	return direct;
}

int GameCharacter::gethealth()
{
	return health;
}

void GameCharacter::setx(int new_x)
{
	coord_x = new_x;
}

void GameCharacter::sety(int new_y)
{
	coord_y = new_y;
}

void GameCharacter::setdirection(direction new_dir)
{
	direct = new_dir;
}

void GameCharacter::sethealth(int new_health)
{
	health = new_health;
}

void GameCharacter::dig()
{

}
