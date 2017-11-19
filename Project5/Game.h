#ifndef _DIGGER_MYMAIN_H_
#define _DIGGER_MYMAIN_H_

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
//#include <functional>
#include <map>
#include <typeinfo>

#include "TextureManager.h"
#include "GameCharacter.h"



class Game {

private:
	bool    running;
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	const int FPS = 60;
	const int FrameDelay = 1000 / 60;
	Uint32 FrameStart;
	int FrameTime;
public:
	Game();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();

	bool isrunning() {
		return running;
	}
	


	int OnExecute();

	
};

#endif