#include "Main.h"


MyMain::MyMain() {

		gWindow = NULL;
		kScreenWidth = 1000;
		kScreenHeight = 700;

		Surf_Menu = NULL;
		Surf_Display = NULL;

		running = true;
}



int MyMain::OnExecute() {

	if (!OnInit())
	{
		return 1;
	}
	else
	{
		SDL_Event Event;
		while (running)
		{
			Surf_Menu = DSurface::OnLoad("C:/Users/Beautiful/Documents/Visual Studio 2017/Projects/Project5/Images/VTITLE.bmp");
			SDL_BlitSurface(Surf_Menu, NULL, Surf_Display, NULL);
			SDL_Rect stretchRect;
			stretchRect.x = 200;
			stretchRect.y = 0;
			stretchRect.w = kScreenWidth;
			stretchRect.h = kScreenHeight;
			SDL_BlitScaled(Surf_Menu, NULL, Surf_Display, &stretchRect);
			//SDL_BlitScaled(Surf_Menu, NULL, Surf_Display, NULL);
			OnRender();
			//loadmenusurface
			while (SDL_PollEvent(&Event)) {
				//OnEvent(&Event);
			}
			//OnLoop();
			
		}
		OnCleanup();
		return 0;
	}
}

	int main(int argc, char* argv[]) {
		MyMain theApp;

		return theApp.OnExecute();
	}
