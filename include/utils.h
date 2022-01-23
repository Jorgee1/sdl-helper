#include <stdbool.h>
#include <SDL.h>

#include "controller.h"

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
    SDL_Rect position;
    bool left_button;
} Mouse;


typedef struct
{
    char *name;
    int view_index;
    int exit;

    SDL_Rect rect;
    SDL_Color clear_color;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Input input;
    Mouse mouse;
} Screen;

int init_screen(
    Screen *,
    char *,
    int,
    int,
    SDL_Color,
    int,
    int
);

void delete_screen(Screen *);


int check_collition(SDL_FRect, SDL_FRect);
void set_render_draw_color(SDL_Renderer*, SDL_Color);

#endif
