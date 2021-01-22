#include <SDL.h>

#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef struct
{
    int key;
    int state;
    int action_state;
    int action_flag;
} Button;

typedef struct
{
    Button up;
    Button down;
    Button left;
    Button right;
    Button action;
    Button cancel;
    Button start;
} Input;

void update_buttons(Button*[], int);

#endif