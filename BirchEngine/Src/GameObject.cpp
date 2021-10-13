#include "GameObject.h"
#include "TextureManager.h"



GameObject::GameObject(const char* texturesheet, int x, int y) 
{
	
		objTexture = TextureManager::LoadTexture(texturesheet); 
		xpos = x; 
		ypos = y; 


}
GameObject::~GameObject() 
{
}
void GameObject::Update()
{
	//movement code and behavior
	xpos++; 
	ypos++; 

	srcRect.h = 32; 
	srcRect.w = 32; 
	srcRect.x = 0 ;
	srcRect.y = 0 ;

	destRect.x = xpos; 
	destRect.y = ypos; 
	destRect.w = srcRect.w * 2; 
	destRect.h = srcRect.h * 2;

		
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect); 
}
