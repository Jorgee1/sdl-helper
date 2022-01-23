#include "utils.h"

int init_screen(
    Screen *screen,
    char *name,
    int w,
    int h,
    SDL_Color clear_color,
    int init_flags,
    int render_flags
)
{
    screen->rect.x = 0;
    screen->rect.y = 0;
    screen->rect.w = w;
    screen->rect.h = h;

    screen->name = name;
    screen->clear_color = clear_color;
    screen->exit = SDL_GAME_RUN;


    if(SDL_Init(init_flags)) return 1;

    screen->window = SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        w,
        h,
        SDL_WINDOW_HIDDEN
    );
    if (screen->window == NULL) return 1;


    screen->renderer = SDL_CreateRenderer(
        screen->window, -1, render_flags
    );
    if (screen->renderer == NULL) return 1;

    screen->mouse.position = (SDL_Rect) {0, 0, 10, 10};
    screen->mouse.left_button = false;

    SDL_ShowWindow(screen->window);

    return 0;
}

void delete_screen(Screen *screen)
{
    SDL_DestroyRenderer(screen->renderer);
    SDL_DestroyWindow(screen->window);
    screen->renderer = NULL;
    screen->window = NULL;

    SDL_Quit();
}

void set_render_draw_color(SDL_Renderer* renderer, SDL_Color color)
{
    SDL_SetRenderDrawColor(
        renderer,
        color.r,
        color.g, 
        color.b,
        color.a
    );
}

int check_collition(SDL_FRect A, SDL_FRect B)
{
    /// PARA A
    int A_IZQ = A.x;
    int A_DER = A.x + A.w;
    int A_ARR = A.y;
    int A_ABJ = A.y + A.h;
    /// PARA B
    int B_IZQ = B.x;
    int B_DER = B.x + B.w;
    int B_ARR = B.y;
    int B_ABJ = B.y + B.h;
    /// Restriccones
    if(
        (A_ABJ >= B_ARR) &&
        (A_ARR <= B_ABJ) &&
        (A_DER >= B_IZQ) &&
        (A_IZQ <= B_DER) 
    ){
        return 1;
    }
    return 0;
}