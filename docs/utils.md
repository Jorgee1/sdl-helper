# Utils

Code that holds varius usefull structures and functions.
Probably will be splitted in the future.

## Screen

```c
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
```

Structure used to keep the window, renderer and some meta-data on the same place.

view_index is used to keep track of the current view, this is defined on the aplication and used on the main loop.

## Color

```c
typedef struct
{
    SDL_Color red;
    SDL_Color green;
    SDL_Color blue;
    SDL_Color white;
    SDL_Color black;
} Colors;
```

Structure to keep track of diferent color on the same place.
Mostly used to provide contrast on menus.

## Collition detection

```c
    int check_collition(SDL_Rect, SDL_Rect);
```

function to check if two rects are intersecting.
Returns 1 if they are, 0 if they aren't.
