#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include<vector>
#include<deque>
#include"game.h"

int main(int argc, char** argv)
{

    if (Initialize()) {
        while (running) {processInput();
   
            createFoods();

                 
            updateHead();
            checkCollisions();
            eatFood();

            render();
        }
    }
    Shutdown();

	return 0;
}