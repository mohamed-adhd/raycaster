//the thing is , its never abt how much pojects i make , it will never be enough , i , will never be enough







// raycasting was such a beautiful concept , yet , its not enough , yes it was difficult , and the dda conceptas well , which i m gonna add , but they re not challenging enough to satisfy..
#include "headers.h"
#define FOV (3.14f / 2.5f)

int main(void){
    float playerx = 1.5f;
    float playery= 1.5f;
    int playercol;
    int playerrow;
    float playerangle;
    int playerdir=1;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* window=SDL_CreateWindow("fuckass fractal",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,0);
    bool running=true;
    SDL_Event event;
    SDL_Texture* seletex;
    SDL_Surface* surf=IMG_Load("backrooms.png");
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Surface* surfcar=IMG_Load("car.png");
    SDL_Texture* texcar=SDL_CreateTextureFromSurface(renderer,surfcar);
    SDL_Surface* whs=IMG_Load("wh.png");
    SDL_Texture* wht=SDL_CreateTextureFromSurface(renderer,whs);
    SDL_SetTextureBlendMode(texcar,SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(wht,SDL_BLENDMODE_BLEND);



    SDL_Surface* whls=IMG_Load("whl.png");
    SDL_Texture* whlt=SDL_CreateTextureFromSurface(renderer,whls);



    SDL_Surface* whrs=IMG_Load("whr.png");
    SDL_Texture* whrt=SDL_CreateTextureFromSurface(renderer,whrs);
    int carw,carh;
    SDL_QueryTexture(tex, NULL, NULL, &carw, &carh);
    SDL_Rect rect={0,0,1280,720};
    SDL_Rect wh={110,480,580,400};
    int texw,texh;
    SDL_QueryTexture(tex, NULL, NULL, &texw, &texh);
    SDL_ShowCursor(SDL_DISABLE ); 
    SDL_SetRelativeMouseMode(SDL_TRUE); 
    Uint32 lastMotionTime = 0;
    seletex=wht;
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
                     
                    
                    float nextx = playerx - cos(playerangle) * 0.1f;
                    float nexty = playery - sin(playerangle) * 0.1f; 
                    
                    
                    if(damap[(int)(nexty)][(int)(nextx)]==0){
                        playery=nexty;
                        playerx=nextx;}
                }else if(key==SDLK_LEFT){
                    
                    
                    float nextx = playerx + cos(playerangle-3.14f/2) * 0.1f;
                    float nexty = playery + sin(playerangle-3.14f/2) * 0.1f; 
                    
                    
                    if(damap[(int)(nexty)][(int)(nextx)]==0){
                        playery=nexty;
                        playerx=nextx;}

                }else if(key==SDLK_RIGHT){
                    
                    
                    float nextx = playerx + cos(playerangle+3.14f/2) * 0.1f;
                    float nexty = playery + sin(playerangle+3.14f/2) * 0.1f; 
                    
                    
                    if(damap[(int)(nexty)][(int)(nextx)]==0){
                        playery=nexty;
                        playerx=nextx;}

                }
            }else if (event.type==SDL_MOUSEMOTION){
                lastMotionTime = SDL_GetTicks();
                playerangle+=event.motion.xrel*0.003;
                if(event.motion.xrel<0){
                    seletex=whlt;
                    
                }else if(event.motion.xrel>0) {
                    seletex=whrt;

                }else if(event.motion.xrel%1280==0){
                seletex=wht;
            }
                
                




            }
        
        }
        if (SDL_GetTicks() - lastMotionTime > 65) { 
        seletex = wht;  
}
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        for(int h=0;h<1280;h++){

            int mapx=(int)(playerx),mapy=(int)(playery);
            float dotx=playerx;
            float doty=playery;
            int hitside;
            float rayangle = playerangle + (h-640)*(FOV/1280); 
            float raydirx=cos(rayangle);
            float raydiry=sin(rayangle);
            float sidedestx=(floor(playerx)+1 -playerx)/raydirx;
            float sidedesty=(floor(playery)+1 -playery)/raydiry;
            if(raydirx<=0){
                 sidedestx=(floor(playerx) -playerx)/raydirx;
            }else{
                 sidedestx=(floor(playerx)+1 -playerx)/fabs(raydirx);
            }
            if(raydiry<=0){
                 sidedesty=(floor(playery) -playery)/raydiry;
            }else{
                 sidedesty=(floor(playery)+1 -playery)/fabs(raydiry);
            }
            
            float deltadistx = 1.0f / fabs(raydirx);
            float deltadisty = 1.0f / fabs(raydiry);
            int stepx = (raydirx >= 0) ? 1 : -1;
            int stepy = (raydiry >= 0) ? 1 : -1;
            while(damap[mapy][mapx]==0){

                if(sidedesty<sidedestx){
                    mapy+=stepy;
                    sidedesty+=deltadisty;
                    hitside=1;


                }else{
                    mapx+=stepx;
                    sidedestx+=deltadistx;
                    hitside=0;
                }
                
                if(mapx<0 || mapx>=10 || mapy<0 || mapy>=10) break;
                
            }
            float d;
            if (hitside==0){
                d=sidedestx-deltadistx;
            }else if (hitside==1){
                d=sidedesty-deltadisty;
            }
            float wallx;
            if(hitside==0){
                wallx=playery+d*raydiry; 

            }else{wallx=playerx+d*raydirx; }
            wallx-=floor(wallx);
            int his=720.0/d;
            float top=360-his/2;
            float bottom=360+his/2;
            int texx=(int)(wallx*texw);
            SDL_Rect rec={texx,0,1,texh};
            SDL_Rect dst={h,top,1,bottom-top};
            float brightness = 255.0f / (1.0f +d*d*2.0f);
            SDL_SetTextureColorMod(tex,brightness+100,brightness+100,brightness+100);
            SDL_RenderCopy(renderer, tex, &rec, &dst);
            
            


            




        }
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        







        
        SDL_RenderCopy(renderer, texcar, &rect, NULL);
        SDL_RenderCopy(renderer, seletex, NULL, &wh);
        

        playercol=(int)playerx;
        playerrow=(int)playery;
        SDL_RenderPresent(renderer);

    }
}

//the dopamine of the bug fixing is addictive , i cant stop , i m seeking more the more i get