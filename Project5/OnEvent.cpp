#include "Main.h"

void MyMain::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

void MyMain::OnExit() {
	running = false;
}
