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
        ||  head.y < CELL * 4
        )
    {
        lose=true;
        setDir(0,0);
    }
}

SDL_Rect ramdomCell(){
    SDL_Rect res;
    res.x = rand() % (COL-2) * CELL + CELL;
    res.y = rand() % (ROW-5) * CELL + 4*CELL;
    res.w = CELL; res.h = CELL;
    return res;
}
void makeTLfood(){
        telefood.first = ramdomCell();
        telefood.second = ramdomCell();
        //Check intersect snake
        for(SDL_Rect& segment : snake){
            if(SDL_HasIntersection(&segment,&telefood.first)){
                telefood.first = ramdomCell();
            }
            if(SDL_HasIntersection(&segment,&telefood.second)){
                telefood.second = ramdomCell();
            }
        }
}

bool collisonWithTLFood(){
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
    SDL_Rect temp;
    //board
    SDL_RenderCopy(renderer,board,NULL,NULL);

    // Draw foods
    temp = telefood.first; temp.h += 5;
    SDL_RenderCopy(renderer,foodTexture,NULL,&temp);
    temp = telefood.second; temp.h += 5;
    SDL_RenderCopy(renderer,foodTexture,NULL,&temp);

    // Draw snake's
    SDL_SetRenderDrawColor(renderer, 60, 100, 220, SDL_ALPHA_OPAQUE);

    for (SDL_Rect& segment : snake){
        temp = segment;
        if(SDL_HasIntersection(&temp,&head)){
            temp.x -= 5;
            temp.y -= 5;
            temp.w += 10;
            temp.h += 15;
            SDL_RenderCopy(renderer,headTexture,NULL,&temp);
        }
        else{
            temp.h += 5;
            SDL_RenderCopy(renderer,bodyTexture,NULL,&temp);
        }
    }
}



