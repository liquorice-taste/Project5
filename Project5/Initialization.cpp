#include "Main.h"
#include "Surface.h"

bool MyMain::OnInit() {
	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize" << SDL_GetError << std::endl;
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("DIGGER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, kScreenWidth, kScreenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			if ((Surf_Display = SDL_GetWindowSurface(gWindow)) == NULL) {
				printf("Couldn't get window surface! SDL_Error: %s\n", SDL_GetError());
			}
		}


		
	}
	
	return true;
}