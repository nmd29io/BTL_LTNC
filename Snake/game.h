#pragma once
#include "global.h"

bool isInRect(int &x, int &y, SDL_Rect rect){
    return x > rect.x && x < rect.w + rect.x && y > rect.y && y < rect.h + rect.y;
} 
void initSnake(){
    snake.resize(3);
    SnakeSize = 3;
    for (int i = 0; i < SnakeSize; ++i) {
        snake[i].x = CELL*(COL/6 -i);
        snake[i].y = CELL*(ROW/2 -i);
    }
}
bool lose =false;
void makeTLfood();
void newgame(){
    delay = DELAY;
    lose =false;
    snake.clear();
    foods.clear();
    FoodsNumber=FOOD;
    FoodsEated =0;
    direction.x=CELL;direction.y=0;
    makeTLfood();
    initSnake();
}

void updateHead() {

    // Move the snake
    if(!(direction.x == 0 && direction.y ==0)){
        head.x = snake.front().x + direction.x;
        head.y = snake.front().y + direction.y;

        snake.push_front(head);
        if (int(snake.size()) > SnakeSize) { snake.pop_back(); }
    }
}
void checkCollisions() {
    // Check for collisions with snake's body
    for (int i = 1; i < SnakeSize; i++) {
        if (SDL_HasIntersection(&snake[0],&snake[i])) {
            lose=true;break;

        }
    }

    // Check for collisions with window boundaries
    if (    head.x > COL * CELL - CELL -CELL 
        ||  head.y > ROW * CELL - CELL -CELL 
        ||  head.x < CELL 
        ||  head.y < CELL 
        ) 
    {
        lose=true;
        direction.x=-direction.x;
        direction.y=-direction.y;


    }
    
}

SDL_Rect ramdomCell(){
    SDL_Rect res;
    res.x = rand() % (COL-2) * CELL + CELL;
    res.y = rand() % (ROW-2) * CELL + CELL;
    res.w = CELL; res.h = CELL;
    return res;
}
void makeTLfood(){
        telefood.first = ramdomCell();
        telefood.second = ramdomCell();
        

}

bool collisonWithTeleFood(){
    if(SDL_HasIntersection(&head,&telefood.first)){
        head = telefood.second;
        FoodsEated++;snake.push_front(head);SnakeSize += 1;return true;
    }    
    if(SDL_HasIntersection(&head,&telefood.second)){
        head = telefood.first;
        FoodsEated++;snake.push_front(head);SnakeSize += 1;return true;
    }
    else return false;
}

void renderGame(SDL_Texture *board, SDL_Texture *foodTexture, SDL_Texture *bodyTexture,SDL_Texture *headTexture) {

    //board
    SDL_RenderCopy(renderer,board,NULL,NULL);

    // Draw foods /
    SDL_RenderCopy(renderer,foodTexture,NULL,&telefood.first);
    SDL_RenderCopy(renderer,foodTexture,NULL,&telefood.second);

    // Draw snake's body
    SDL_SetRenderDrawColor(renderer, 60, 100, 220, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& segment : snake)
        SDL_RenderCopy(renderer,bodyTexture,NULL,&segment);

    // Draw snake head 
    SDL_Rect pos = head;
    pos.x -= 5;
    pos.y -= 5;
    pos.w += 10;
    pos.h += 10;
    SDL_RenderCopy(renderer,headTexture,NULL,&pos);


}



