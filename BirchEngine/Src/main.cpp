#include "Game.h"
#include <iostream>


Game *game = nullptr;


SDL_DisplayMode currentDisplay; 





int main(int argc, char *argv[])
{
	const int FPS = 60; 
	const int frameDelay = 1000 / FPS; 
	Uint32 frameStart; 
	int frameTime; 
		
	//ejm 
	

	game = new Game();
	game->init ("GameWindow",800 ,600, false);
	//game->init("GameWindow", currentDisplay.w, currentDisplay.h, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks(); 

		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart; 
		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime); 
		}
		
		
		
		
		
		std::cout << frameTime << std::endl; 
		//







	}

	game->clean();
	return 0;
}