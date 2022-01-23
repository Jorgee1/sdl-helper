# Controller

Code to handle player input.

## Button

```c
typedef struct
{
    int key;
    int state;
    int action_state;
    int action_flag;
} Button;
```
This struct holds all the date related to the button

* key: SDL ScanCode representation of a key.
* state: Holds the state of the key. If pressed state is 1, if unpressed is state is 0.
* action_state: This state is used for menus, if the key is pressed only triggers for one frame, then it turns 0.
* action_flag: Flag to keep track of the action_state.

## Actions

```c
struct Input
{
    Button up;
    Button down;
    Button left;
    Button right;
    Button action;
    Button cancel;
    Button start;
};
```

Structure that maps keys to actions, should be declared once. Used to standarize player actions.

Posible buttons are as follows:

* action
* cancel
* start

Directional pad:

* up
* down
* left
* right

## Update buttons

```c
void update_buttons(Button* buttons[], int size);
```

Must be called on every frame to update the state of the buttons.

