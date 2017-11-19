#include "Game.h"	

void OnKeyDown(SDL_Scancode key, Uint16 unicode)
{
}


void Game::OnEvent(SDL_Event* Event) {
	switch (Event->type) {
	case SDL_KEYDOWN: {
		OnKeyDown(Event->key.keysym.scancode, Event->key.keysym.mod);
		break;
	}

	case SDL_QUIT: {
		running = false;
		break;
	}

	default: {
		//OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
		break;
	}
	}
}

