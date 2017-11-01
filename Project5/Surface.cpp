#include "Surface.h"
#include "Main.h"

DSurface::DSurface() {
}

SDL_Surface* DSurface::OnLoad(const char* File) {
	//SDL_Surface* Surf_Optimized = NULL;
	SDL_Surface* Surf_Loaded = NULL;

	if ((Surf_Loaded = SDL_LoadBMP(File)) == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", File, SDL_GetError());
	}
	
	//else
	/*{
		MyMain k;

		Surf_Optimized = SDL_ConvertSurface(Surf_Loaded, k.Surf_Display->format, NULL);

		if (Surf_Optimized == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", File, SDL_GetError());
		}

		SDL_FreeSurface(Surf_Loaded);
	} */

	return Surf_Loaded;
}

