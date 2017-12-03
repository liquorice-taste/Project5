#ifndef _DIGGER_GAMECHARACTER_H_
#define _DIGGER_GAMECHARACTER_H_

#include "Game.h"
enum direction { Up, Down, Left, Right };

class GameCharacter {
protected:
	direction direct;
	int coord_x, coord_y, health;
	SDL_Texture* chTex;
	SDL_Rect srcRect, destRect;
	//SDL_Renderer* Ren;
public:
	GameCharacter(const char* texturesheet, int x, int y);
	virtual ~GameCharacter() = 0 {};

	void Update();
	void Render();

	int getx();
	int gety();
	direction getdirection();
	int gethealth();

	void setx(int);
	void sety(int);
	void setdirection(direction);
	void sethealth(int);
private:
};

class Digger : public GameCharacter
{
public:
	Digger(const char* texturesheet,int x, int y) : GameCharacter(texturesheet, x, y) {};
private:

};

#endif