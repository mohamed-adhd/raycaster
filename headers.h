#include <stdio.h>
#include "stdbool.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int damap[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,1,0,1,0,1,0,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,1,0,1,0,1,0,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,1,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1}};
float playerx=5.5;
float playery=5.5;