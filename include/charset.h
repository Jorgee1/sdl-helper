#include <SDL.h>
#include <SDL_ttf.h>

#ifndef CHARSET_H
#define CHARSET_H

typedef struct
{
    char letter;
    SDL_Texture* texture;
    int h;
    int w;	
} Letter;

void create_charset(SDL_Renderer*, TTF_Font*, Letter[], int, SDL_Color);

int get_string_w(Letter*, char[]);

int get_string_h(Letter*, char[]);

void destroy_charset(Letter[], int);

void render_string(SDL_Renderer*, int, int, Letter*, char[]);

#endif
