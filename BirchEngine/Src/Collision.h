#pragma once
#include "SDL.h"



class Collision 
{
public: 
	//do detection
	static bool AABB(const SDL_Rect& recA, SDL_Rect& recB);
	
}; 