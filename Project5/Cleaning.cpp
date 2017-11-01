#include "Main.h"

void MyMain::OnCleanup() {

	SDL_FreeSurface(Surf_Display);
	Surf_Display = NULL;

	SDL_DestroyWindow(gWindow);

	gWindow = NULL;
	SDL_Quit();

	}