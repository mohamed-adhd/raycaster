//the thing is , its never abt how much pojects i make , it will never be enough , i , will never be enough








#include "headers.h"


int main(void){
    int playercol;
    int playerrow;
    float playerangle;
    int playerdir;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window=SDL_CreateWindow("fuckass fractal",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,0);
    bool running=true;
    SDL_Event event;
    while (running){
        while(SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                running=false;
            }else if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if(key==SDLK_UP){
                    if(damap[playerrow-1][playercol]==0){
                        playery-=0.1;
                    }
                }else if(key==SDLK_DOWN){
                    if(damap[playerrow+1][playercol]==0){
                        playery+=0.1;
                    }

                }else if(key==SDLK_LEFT){
                    if(damap[playerrow][playercol-1]==0){
                        playerx-=0.1;
                    }

                }else if(key==SDLK_RIGHT){
                    if(damap[playerrow][playercol+1]==0){
                        playerx+=0.1;
                    }

                }
            }else if (event.type==SDL_MOUSEMOTION){
                int mousex=event.motion.x;
                int mouserat=mousex/1280.0;
                playerangle=mouserat*360;
                if(playerangle==0){
                    printf("you facing left");
                }else if(playerangle==90){
                    printf("you facing right");
                }




            }
        }SDL_RenderClear(renderer);









        playercol=(int)playerx;
        playerrow=(int)playery;
        SDL_RenderPresent(renderer);
    }
}