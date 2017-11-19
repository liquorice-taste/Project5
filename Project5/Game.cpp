#include "Game.h"

Digger* digger;

Game::Game() {

	Window = NULL;
	Renderer = NULL;
	running = true;
}

int Game::OnExecute() {
	if (!OnInit())
	{
		return 1;
		
	}
	else
	{
		SDL_Event Event;
		while (running)
		{
			FrameStart = SDL_GetTicks();

			//Events
			OnLoop();
			OnRender();

			FrameTime = SDL_GetTicks() - FrameStart;
			if (FrameDelay > FrameTime) {
				SDL_Delay(FrameDelay - FrameTime);
			}
		}
		OnCleanup();
		return 0;
	}
}

	int main(int argc, char* argv[]) {
		Game *theDigger = new Game();
		return theDigger->OnExecute();
	}

	


	bool Game::OnInit() {

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "SDL could not be initialized" << SDL_GetError << std::endl;
			return false;
		}
		else
		{
			Window = SDL_CreateWindow("DIGGER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL); //SDL_WINDOW_FULLSCREEN_DESKTOP

			if (Window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				return false;
			}
			else
			{
				Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
				if (Renderer) {
					SDL_SetRenderDrawColor(Renderer, 0, 255, 255, 255);
				}
			}
			digger = new Digger("C:/Users/Beautiful/Desktop/Digger/BMPS/VEMERALD.bmp", Renderer, 25, 25);
			
		}
		return true;
	}

	void Game::OnLoop() {
		
		/*TEST CODE STARTS HERE
		SDL_Texture* texture = IMG_LoadTexture(Renderer, "C:/Users/Beautiful/Desktop/Digger/BMPS/VEMERALD.bmp");
		SDL_Rect texture_rect;
		texture_rect.x = 0+i;  //the x coordinate
		texture_rect.y = 0+i; // the y coordinate
		texture_rect.w = 50; //the width of the texture
		texture_rect.h = 50;

		SDL_RenderClear(Renderer);
		SDL_RenderCopy(Renderer, texture, NULL, &texture_rect);
		SDL_RenderPresent(Renderer);
		TEST CODE ENDS HERE*/
		
		digger->Update();
	}

	void Game::OnRender() {
		//SDL_RenderClear(Renderer);
		digger->Render();
		SDL_RenderPresent(Renderer);
	}

	void Game::OnCleanup() {

		SDL_DestroyWindow(Window);
		Window = NULL;

		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;

		IMG_Quit();
		SDL_Quit();

	}