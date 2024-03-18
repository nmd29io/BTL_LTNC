#include"game.h"
#include"menu.h"
#include"button.h"



int main(int argc, char** argv)
{

const char* path[13];
int frame = 1;
path[0]="D:\\Project1\\snakeEye\\snakeEye1.png";
path[1]="D:\\Project1\\snakeEye\\snakeEye1.png";
path[2]="D:\\Project1\\snakeEye\\snakeEye2.png";
path[3]="D:\\Project1\\snakeEye\\snakeEye3.png";
path[4]="D:\\Project1\\snakeEye\\snakeEye4.png";
path[5]="D:\\Project1\\snakeEye\\snakeEye5.png";
path[6]="D:\\Project1\\snakeEye\\snakeEye6.png";
path[7]="D:\\Project1\\snakeEye\\snakeEye7.png";
path[8]="D:\\Project1\\snakeEye\\snakeEye8.png";
path[9]="D:\\Project1\\snakeEye\\snakeEye9.png";
path[10]="D:\\Project1\\snakeEye\\snakeEye10.png";
path[11]="D:\\Project1\\snakeEye\\snakeEye11.png";
path[12]="D:\\Project1\\snakeEye\\snakeEye12.png";


    if (Initialize()) {
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
                else if (event.type == SDL_KEYDOWN) {
                    switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        if(direction.y == 0)
                        {direction.x = 0; direction.y = -CELL;}
                        break;
                    case SDLK_DOWN:
                        if(direction.y == 0)
                        {direction.x = 0; direction.y = CELL;}
                        break;
                    case SDLK_LEFT:
                        if(direction.x == 0)
                        {direction.x = -CELL; direction.y = 0;}
                        break;
                    case SDLK_RIGHT:
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
            if(lose){

                gameOver();SDL_Delay(50);
            }
            else{
            
            
            createFoods();
                 
            
            
            eatFood();
        

            renderBaseGame();

                texture = IMG_LoadTexture(renderer, path[frame%13]); 
                SDL_RenderCopy(renderer,texture,NULL,&head);
            frame++;
            }
                score();
            here:
            SDL_RenderPresent(renderer);
            SDL_Delay(delay);
        }
    }
    Shutdown();

	return 0;
}