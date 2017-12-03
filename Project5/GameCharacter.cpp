#include "GameCharacter.h"
#include "TextureManager.h"
#include "Define.h"
//#include "Game.h"
GameCharacter::GameCharacter(const char* texturesheet, int x, int y)
{
	chTex = TextureManager::LoadTexture(texturesheet);
	coord_x = x;
	coord_y = y;
}


void GameCharacter::Update()
{
	srcRect.h = GAME_OBJ_HEIGHT;
	srcRect.w = GAME_OBJ_WIDTH;
	srcRect.x = 0;
	srcRect.y = 0;


	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = coord_x;
	destRect.y = coord_y;
	
}

void GameCharacter::Render()
{
	SDL_RenderCopy(Game::Renderer, chTex, &srcRect, &destRect);
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

