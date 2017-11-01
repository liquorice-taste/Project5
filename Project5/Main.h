#ifndef _DIGGER_MYMAIN_H_
#define _DIGGER_MYMAIN_H_

#include <SDL.h>
#include <iostream>
#include <stdio.h>

#include "Commands.h"
#include "Event.h"
#include "Surface.h"

class MyMain {
private:
	bool    running;
	
	int kScreenWidth;
	int kScreenHeight;

	
public:
	SDL_Window* gWindow;
	SDL_Surface* Surf_Menu;
	SDL_Surface* Surf_Display;

	MyMain();

	bool OnInit();

	//void OnEvent(SDL_Event* Event);

	//void OnLoop();

	void OnRender();

	void OnCleanup();

	//void OnExit();

	int OnExecute();

	
};

#endif