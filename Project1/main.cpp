#include"game.h"
#include"menu.h"
#include"button.h"


int main(int argc, char** argv)
{

const char* path[13];
int frame = 1;
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
        while (running) {Input();
   
            createFoods();
                 
            updateHead();
            checkCollisions();
            eatFood();

            renderBaseGame();

                texture = IMG_LoadTexture(renderer, path[frame%13]); 
                SDL_RenderCopy(renderer,texture,NULL,&head);
            frame++;
            SDL_RenderPresent(renderer);
            SDL_Delay(150);
        }
    }
    Shutdown();

	return 0;
}