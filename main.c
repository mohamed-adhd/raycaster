//the thing is , its never abt how much pojects i make , it will never be enough , i , will never be enough








#include "headers.h"


int main(void){
    float playerx=5.5f;
    float playery=5.5f;
    int playercol;
    int playerrow;
    float playerangle;
    int playerdir=1;
    ray
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window=SDL_CreateWindow("fuckass fractal",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,0);
    bool running=true;
    SDL_Event event;
    while (running){
        playercol=(int)playerx;
        playerrow=(int)playery;
        while(SDL_PollEvent(&event)){
            
            if (event.type==SDL_QUIT){
                running=false;
            }else if(event.type==SDL_KEYDOWN){
                SDL_Keycode key=event.key.keysym.sym;
                if(key==SDLK_UP){
                    int nextrow = (int)(playery - 0.1f);
                    if(damap[nextrow][playercol]==0){
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

                }else if (key==SDLK_SPACE){
                    if(playerdir==1){
                        printf("you facing east");
                    
                    }else if(playerdir==2){
                        printf("you facing north");
                        
                    }else if(playerdir==3){
                        printf("you facing west");
                        
                    }else if(playerdir==4){
                        printf("you facing south");
                    
                }
                }
            }else if (event.type==SDL_MOUSEMOTION){
                int mousex=event.motion.x;
                float mouserat=(float)mousex/1280.0f;
                playerangle=mouserat*360;
                if(0<=playerangle && playerangle<90){
                    playerdir=1;
                }else if(90<=playerangle && playerangle<=180){
                    playerdir=2;
                }else if(180<=playerangle && playerangle<=270){
                    playerdir=3;
                }else if(270<=playerangle && playerangle<=360){
                    playerdir=4;
                }




            }
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        SDL_RenderClear(renderer);









        playercol=(int)playerx;
        playerrow=(int)playery;
        SDL_RenderPresent(renderer);

    }
}