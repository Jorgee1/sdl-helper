#include <SDL.h>
#include <SDL_ttf.h>

#ifndef CHARSET_H
#define CHARSET_H

/** @brief
    Sructure to handle ASCII letters and text using SDL_TTF.
*/

/** This is My Class!
    \class Letter
    */
typedef struct
{
    char letter;
    SDL_Texture* texture;
    int h;
    int w;	
} Letter;


/** A public member function of Letter
    \memberof Letter
    */
int get_string_w(Letter* letters, char word[]);

int get_string_h(Letter*, char[]);

void destroy_charset(Letter[], int);

void create_charset(SDL_Renderer*, TTF_Font*, Letter[], int, SDL_Color);

void render_string(SDL_Renderer*, int, int, Letter*, char[]);

void render_int(SDL_Renderer*, int, int, Letter*, int);

#endif
