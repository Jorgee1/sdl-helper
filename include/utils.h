#include <SDL.h>

#ifndef UTILS_H
#define UTILS_H

enum EXIT_SATE
{
	SDL_GAME_RUN,
	SDL_GAME_EXIT
};

typedef struct
{
	SDL_Color red;
	SDL_Color green;
	SDL_Color blue;
	SDL_Color white;
	SDL_Color black;
} Colors;

typedef struct
{
	char *name;
	int view_index;
	int exit;
	
	SDL_Rect rect;
	SDL_Color clear_color;
	SDL_Window* window;
	SDL_Renderer* renderer;
} Screen;

int check_collition(SDL_Rect, SDL_Rect);

#endif
