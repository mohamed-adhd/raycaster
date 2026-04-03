//the thing is , its never abt how much pojects i make , it will never be enough , i , will never be enough








#include "headers.h"
#define FOV (3.14f / 3.0f)

int main(void){
    float playerx=5.5f;
    float playery=5.5f;
    int playercol;
    int playerrow;
    float playerangle;
    int playerdir=1;
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
                playerangle=mouserat*2*(3.14f);
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
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        for(int h=0;h<1280;h++){
            float dotx=playerx;
            float doty=playery;
            float rayangle = playerangle + (h-640)*(FOV/1280); 
            float raydirx=cos(rayangle);
            float raydiry=sin(rayangle);
            while(damap[(int)doty][(int)dotx]==0){
                dotx+=raydirx*0.01f;
                doty+=raydiry*0.01f;
                if(dotx<0 || dotx>=10 || doty<0 || doty>=10) break;
                
            }
            float d=sqrt((pow((dotx-playerx),2)+pow(doty-playery,2)));
            float his= (float)(720/d);
            float top=360+his/2;
            float bottom=360-his/2;
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            SDL_RenderDrawLine(renderer,h,top,h,bottom);

            




        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        









        playercol=(int)playerx;
        playerrow=(int)playery;
        SDL_RenderPresent(renderer);

    }
}