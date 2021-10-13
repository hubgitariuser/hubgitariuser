#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer(nullptr);
SDL_Event Game::event;
auto& player(manager.addEntity()); // create player
auto& wall(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	map = new Map(); 
	//playerTex = TextureManager::LoadTexture(("assets/player.png"), renderer); 
	/* //old code before texture class 
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png"); 
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface); 
	SDL_FreeSurface(tmpSurface); 
	*/
	//playerEntity
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/player.png"); 
	player.addComponent<KeyboardController>();
	player.addComponent <ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	wall.addComponent<ColliderComponent>("wall"); 

}

void Game::handleEvents()
{
	int xx = 0; 
	
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	case SDL_MOUSEMOTION:
		std::cout << event.motion.x; 
	//	int mouseX = event.motion.x;
	//	int mouseY = event.motion.y;
	//	int mouseY = event.motion.y;
	//	std::cout << "mouse x: " << mouseX; 
	
		break;
		
	case SDL_MOUSEBUTTONDOWN:
		
	default:
		break;
	}
}

void Game::update()
{
	manager.refresh(); 
	manager.update(); 

	


	
	/*
	std::cout << newPlayer.getComponent<PositionComponent>().x() << ","  << 
	newPlayer.getComponent<PositionComponent>().y() << "," << std::endl ; 
	*/

}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(); 
	
	manager.draw(); 
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}