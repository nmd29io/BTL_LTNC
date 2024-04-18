#pragma once
#include "game.h"
enum Dir
{
	RIGHT,LEFT,UP,DOWN
};
std::queue<int> inputQueue;

void input(SDL_Event &e, State state  ){
	while (SDL_PollEvent(&e)) {                
                                switch(e.type)
                                {
                                    case SDL_QUIT:
                                        state = EXIT;
                                    break;
                                    case SDL_KEYDOWN:                           
                                                                   
                                        switch (e.key.keysym.sym) 
                                        {
                                        case SDLK_UP:pause = false;
                                            if(inputQueue.back() != DOWN)
                                            	inputQueue.push(UP);
                                            break;
                                        case SDLK_DOWN:pause = false;
                                            if(inputQueue.back() != UP)
                                            	inputQueue.push(DOWN);
                                            break;
                                        case SDLK_LEFT:pause = false;
                                            if(inputQueue.back() != DOWN)
                                            	inputQueue.push(UP);
                                            break;
                                        case SDLK_RIGHT:pause = false;
                                            if(inputQueue.back() != DOWN)
                                            	inputQueue.push(UP);
                                            break;
  
                                        }
                                    break;
                                }
    }  
}
