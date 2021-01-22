# Charset

Code to handle structures for printing text to an SDL window,

## Letter

```c
typedef struct
{
    char letter;
    SDL_Texture* texture;
    int h;
    int w;	
} Letter;
```

Structure used for mapping a letter to a texture (font), it also keeps some meta-data line the width and height.

## Create a Charset

A charset is an array of letters used to keep a texture representation of every letter on the ascii table in a single structure that can be pass arround for displaying strings on the screen.

Declaration:

```c
const int charset_size = 128;
Letter letters[charset_size];
```

Example on how to get the texture representation of a character:

```c
    char c = 'a';
    SDL_Texture* texture = letters[(int) c]
```

This method is is strongly discouraged given the following section.

### Rendering text

```c
void render_string(
    SDL_Renderer* renderer,
    int x,
    int y,
    Letter* letters,
    char[] string
);
```

Function used to display a string on the given renderer.

### String size as textures

```c
int get_string_w(Letter* letters, char[] string);
int get_string_h(Letter* letters, char[] string);
```

These functions are used to get the dimensions a string will have once is rendered. Used mostly for positioning in layouts.
