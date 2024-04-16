 #include"game.h"
#include"menu.h"


int main(int argc, char** argv)
{
srand(time(NULL));
makeTLfood();

const char* path[13];
int frame = 1;
path[0]="snakeEye\\snakeEye1.png";
path[1]="snakeEye\\snakeEye1.png";
path[2]="snakeEye\\snakeEye2.png";
path[3]="snakeEye\\snakeEye3.png";
path[4]="snakeEye\\snakeEye4.png";
path[5]="snakeEye\\snakeEye5.png";
path[6]="snakeEye\\snakeEye6.png";
path[7]="snakeEye\\snakeEye7.png";
path[8]="snakeEye\\snakeEye8.png";
path[9]="snakeEye\\snakeEye9.png";
path[10]="snakeEye\\snakeEye10.png";
path[11]="snakeEye\\snakeEye11.png";
path[12]="snakeEye\\snakeEye12.png";

    initSnake();
    Initialize();
    eatSound = Mix_LoadWAV("sound/crunch.wav");
    //Mix_PlayChannel(-1, eatSound, 0);
    if (running) {

        SDL_Event event;
        int x,y;
        SDL_Color white{255,255,255,255};
        SDL_Color red{255,0,0,255};
        
        renderStartMenu(white);
        renderQuit(white);
        while (StartMenu){
            while (SDL_PollEvent(&event)&&StartMenu) {

                SDL_GetMouseState(&x,&y);
                if (event.type == SDL_QUIT) {StartMenu = false;running = false;}
                if(StartMenu
                && x > startButton.x 
                && x < startButton.w + startButton.x
                && y > startButton.y
                && y < startButton.h + startButton.y){
                    renderStartMenu(red);
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                        StartMenu = false;
                }
                else renderStartMenu(white);
                if(StartMenu
                && x > quitButton.x 
                && x < quitButton.w + quitButton.x
                && y > quitButton.y
                && y < quitButton.h + quitButton.y){
                    renderQuit(red);
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                        {StartMenu = false;running = false;}
                }
                else renderQuit(white);
            }
            SDL_RenderPresent(renderer);
            SDL_Delay(100);
        }
        while (running) {

            
            while (SDL_PollEvent(&event)) {                

                if (event.type == SDL_QUIT) {
                    running = false;
                }
                else if (event.type == SDL_KEYDOWN) {
                    
                    
                    switch (event.key.keysym.sym) {
                    case SDLK_UP:pause = false;
                        if(direction.y == 0)
                        {direction.x = 0; direction.y = -CELL;}
                        break;
                    case SDLK_DOWN:pause = false;
                        if(direction.y == 0)
                        {direction.x = 0; direction.y = CELL;}
                        break;
                    case SDLK_LEFT:pause = false;
                        if(direction.x == 0)
                        {direction.x = -CELL; direction.y = 0;}
                        break;
                    case SDLK_RIGHT:pause = false;
                        if(direction.x == 0)
                        {direction.x = CELL; direction.y = 0;}
                        break;
                    case SDLK_SPACE:
                        pause = !pause;
                        break;
                    case SDLK_r:
                        replay(); lose = false;
                        break;
                    }
                }
            }  
            

            if(pause){
                goto here;

            }
            updateHead();
            checkCollisions();
            here:
            if(lose){

                gameOver();SDL_Delay(50);
            }
            else{
            
            
            // createFoods();
                 
            
            if(tele()){

                delay-=(20/FoodsEated);
                makeTLfood();
                
            }
            eatFood();
        

            renderBaseGame();

                texture = IMG_LoadTexture(renderer, path[frame%13]); 
                SDL_RenderCopy(renderer,texture,NULL,&head);


            frame++;
            }
                score();
            
            SDL_RenderPresent(renderer);
            SDL_Delay(delay);


        }
    }
    Shutdown();
    Mix_FreeChunk(eatSound);

	return 0;
}