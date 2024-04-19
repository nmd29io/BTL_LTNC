#pragma once
#include "global.h"

class SnAkE{
    public:
    SDL_Rect head;
    std::deque<SDL_Rect> body;
    int size = INIT_SIZE;
    SDL_Point dir{ CELL,0 };
    std::queue<SDL_Point> q_dir;
    int score = 0;
};
void renderTwoSnake(SnAkE &a, SnAkE &b){
    SDL_Rect temp;
    //board
    SDL_RenderCopy(renderer,pictures[Board],NULL,NULL);

    // Draw snake's
    temp = a[0];
            temp.x -= 5;
            temp.y -= 5;
            temp.w += 10;
            temp.h += 15;
    SDL_RenderCopy(renderer,pictures[Body],NULL,&temp);
    for(int i = 1; i < a.size; i++){
        temp = a[i];temp.h += 5;
        SDL_RenderCopy(renderer,pictures[Body],NULL,&temp);
    }
    // Draw foods
    temp = telefood.first; temp.h += 5;
    SDL_RenderCopy(renderer,pictures[Food],NULL,&temp);
    temp = telefood.second; temp.h += 5;
    SDL_RenderCopy(renderer,pictures[Food],NULL,&temp);
}
