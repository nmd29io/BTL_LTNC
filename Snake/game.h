#pragma once
#include "global.h"

bool lose =false;
void makeTLfood();
void setCellState(SDL_Rect cell, int x){
    cellState[cell.y/CELL][cell.x/CELL] = x;
}
SDL_Rect ramdomCell(){
    SDL_Rect res;
    res.x = rand() % (COL-2) * CELL + CELL;
    res.y = rand() % (ROW-5) * CELL + 4*CELL;
    res.w = CELL; res.h = CELL;
    for(SDL_Rect& p : snake){
        if(SDL_HasIntersection(&res,&p))
            {
                ramdomCell();
            }
    }
    return res;
}
void newgame(int x, int y){
    for(int i = 0; i < 24; i++)
        for(int j = 0; j < 24; j++)
            if(cellState[i][j] != 9 )cellState[i][j] = 0;
    lose =false;
    pause = false;
    FoodsEated = 0;
    dir = {0,0};
    telefood.first = {0,0,0,0}; telefood.second ={0,0,0,0};
    if(mode == Tele) makeTLfood();else telefood.first = ramdomCell();
    snake.clear();
    SnakeSize = INIT_SIZE;
    SDL_Rect temp;
    for (int i = 0; i < INIT_SIZE; ++i) {
            temp = {CELL*(x + i),CELL*y,CELL,CELL};
            snake.push_front(temp);setCellState(temp,1);
    }
}
int getCellState(SDL_Rect cell){
    return cellState[cell.y/CELL][cell.x/CELL];
}

void updateHead() {
        head = {snake.front().x + dir.x,snake.front().y + dir.y,CELL,CELL};

}

void updateSnake(){
    if(dir.x != 0 || dir.y !=0){
               snake.push_front(head);setCellState(head,1);
    }
    if (int(snake.size()) > SnakeSize) { setCellState(snake.back(),0);snake.pop_back(); }
}

bool checkCollisions() {
    // Check for collisions with snake's body
    for (int i = 1; i < SnakeSize; i++) {
        if (SDL_HasIntersection(&head,&snake[i])) {
            return true;
        }
    }
    // Check for collisions with window boundaries
    if (    head.x > COL * CELL - CELL -CELL
        ||  head.y > ROW * CELL - CELL -CELL
        ||  head.x < CELL
        ||  head.y < CELL * 4
        )
        return true;
    return false;
}



void makeTLfood(){
        telefood.first = ramdomCell();
        telefood.second = ramdomCell();
        if(SDL_HasIntersection(&telefood.first,&telefood.second)) makeTLfood();

        setCellState(telefood.first ,2);
        setCellState(telefood.second ,2);

}

bool collisonWithTLFood(){
    if(SDL_HasIntersection(&head,&telefood.first)){
        if(mode == Tele){ head = telefood.second;}

        FoodsEated++;SnakeSize ++;return true;
    }
    if(SDL_HasIntersection(&head,&telefood.second)){
        if(mode == Tele){ head = telefood.first;}
        FoodsEated++;SnakeSize ++;return true;
    }
    else return false;
}
#if 1
void renderGame(SDL_Texture *pictures[]) {
    SDL_Rect temp;
    //board
    SDL_RenderCopy(renderer,pictures[Board],NULL,NULL);

    // Draw snake's
    temp = snake[0];
            temp.x -= 5;
            temp.y -= 5;
            temp.w += 10;
            temp.h += 15;
    SDL_RenderCopy(renderer,pictures[Body],NULL,&temp);
    for(int i = 1; i < SnakeSize; i++){
        temp = snake[i];temp.h += 5;
        SDL_RenderCopy(renderer,pictures[Body],NULL,&temp);
    }
    // Draw foods
    temp = telefood.first; temp.h += 5;
    SDL_RenderCopy(renderer,pictures[Food],NULL,&temp);
    temp = telefood.second; temp.h += 5;
    SDL_RenderCopy(renderer,pictures[Food],NULL,&temp);
}
#endif // 0


