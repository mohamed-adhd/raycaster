//the thing is , its never abt how much pojects i make , it will never be enough , i , will never be enough







// raycasting was such a beautiful concept , yet , its not enough , yes it was difficult , and the dda conceptas well , which i m gonna add , but they re not challenging enough to satisfy..
#include "headers.h"
#define FOV (3.14f / 2.5f)

int main(void){
    float playerx = 5.5f;
    float playery= 5.5f;
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
                    
                    float nextx = playerx + cos(playerangle) * 0.1f;
                    float nexty = playery + sin(playerangle) * 0.1f; 
                    
                    
                    if(damap[(int)(nexty)][(int)(nextx)]==0){
                        playery=nexty;
                        playerx=nextx;}
                    
                    
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
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
                if(0<=playerangle && playerangle<((3.14f)/2)){
                    playerdir=1;
                }else if(((3.14f)/2)<=playerangle && playerangle<=(3.14f)){
                    playerdir=2;
                }else if((3.14f)<=playerangle && playerangle<=(3*(3.14f)/2)){
                    playerdir=3;
                }else if((3*(3.14f)/2)<=playerangle && playerangle<=2*(3.14f)){
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
            printf("%d",d);
            float his= (float)(720/d);
            float top=360-his/2;
            float bottom=360+his/2;
            if(d<=0.5f){
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
            }else if (0.5f<d && d<=1.0f){
                SDL_SetRenderDrawColor(renderer,248,248,248,255);
            }else if (1.0f<d && d<=1.5f){
                SDL_SetRenderDrawColor(renderer,240,240,240,255);
            }else if (1.5f<d && d<=2.0f){
                SDL_SetRenderDrawColor(renderer,225,225,225,255);
            }else if (2.0f<d && d<=2.5f){
                SDL_SetRenderDrawColor(renderer,210,210,210,255);
            }else if (2.5f<d && d<=3.0f){
                SDL_SetRenderDrawColor(renderer,195,195,195,255);
            }else if (3.0f<d && d<=3.5f){
                SDL_SetRenderDrawColor(renderer,180,180,180,255);
            }else if (3.5f<d && d<=4.0f){
                SDL_SetRenderDrawColor(renderer,165,165,165,255);
            }else if (4.0f<d && d<=4.5f){
                SDL_SetRenderDrawColor(renderer,150,150,150,255);
            }else if (4.5f<d && d<=5.0f){
                SDL_SetRenderDrawColor(renderer,135,135,135,255);
            }else if (5.0f<d && d<=5.5f){
                SDL_SetRenderDrawColor(renderer,120,120,120,255);
            }else if (5.5f<d && d<=6.0f){
                SDL_SetRenderDrawColor(renderer,105,105,105,255);
            }else if (6.0f<d && d<=6.5f){
                SDL_SetRenderDrawColor(renderer,90,90,90,255);
            }else if (6.5f<d && d<=7.0f){
                SDL_SetRenderDrawColor(renderer,75,75,75,255);
            }else if (7.0f<d && d<=7.5f){
                SDL_SetRenderDrawColor(renderer,60,60,60,255);
            }else if (7.5f<d && d<=8.0f){
                SDL_SetRenderDrawColor(renderer,45,45,45,255);
            }else if (8.0f<d && d<=8.5f){
                SDL_SetRenderDrawColor(renderer,30,30,30,255);
            }else if (8.5f<d && d<=9.0f){
                SDL_SetRenderDrawColor(renderer,15,15,15,255);
            }else if (9.0f<d){
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
            }
            SDL_RenderDrawLine(renderer,h,top,h,bottom);

            




        }
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        









        playercol=(int)playerx;
        playerrow=(int)playery;
        SDL_RenderPresent(renderer);

    }
}

//the dopamine of the bug fixing is addictive , i cant stop , i m seeking more the more i get