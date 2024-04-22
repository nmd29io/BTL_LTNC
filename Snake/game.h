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
                return ramdomCell();
            }
    }
    for(auto& p : wall){
        if(SDL_HasIntersection(&p,&res)){
            return ramdomCell();
        }
    }
    return res;
}
SDL_FPoint ramdomDir();
SDL_FPoint fdir;
void newgame(int x, int y){
    for(int i = 0; i < 24; i++)
        for(int j = 0; j < 24; j++)
            if(cellState[i][j] != 9 )cellState[i][j] = 0;

    snake.clear();
    SnakeSize = INIT_SIZE;
    SDL_Rect temp;
    for (int i = 0; i < INIT_SIZE; ++i) {
            temp = {CELL*(x + i),CELL*y,CELL,CELL};
            snake.push_front(temp);setCellState(temp,1);
    }
    lose =false;
    pause = false;
    FoodsEated = 0;
    dir = {0,0};
    p_food.first = {0,0,0,0}; p_food.second ={0,0,0,0};
    if(mode == TeleMode || mode == LockMode) makeTLfood();else p_food.first = ramdomCell();

    fdir = ramdomDir();
    wall.clear();

}
int getCellState(SDL_Rect cell){
    return cellState[cell.y/CELL][cell.x/CELL];
}

SDL_FPoint ramdomDir(){
    int degree_angle = rand()%361;
    float radian_angle = degree_angle*M_PI/360;
//    std::cout<<radian_angle<<' '<<20*cos(radian_angle)<<" "<<20*sin(radian_angle)<<'\n';
    return SDL_FPoint({cos(radian_angle),sin(radian_angle)});
}

void flyFood(SDL_Rect &food){
    int x = food.x + 5*fdir.x;
    int y = food.y + 5*fdir.y;
    SDL_Rect temp = {x,y,CELL,CELL};
//std::cout<< p_food.first.x <<" "<<p_food.first.y <<'\n';
    if(x >= COL * CELL - CELL -CELL || x <= CELL){ fdir.x = -fdir.x;}
    if(y >= COL * CELL - CELL -CELL || y <= 4 * CELL){ fdir.y = -fdir.y;}
    for (int i = 1; i < SnakeSize; i++)
        if (SDL_HasIntersection(&temp,&snake[i])){
            fdir.x = -fdir.x;fdir.y = -fdir.y; break;

        }
    food.x += 4*fdir.x;
    food.y += 4*fdir.y;
    if(food.x < CELL) food.x += CELL;
    if(food.x > COL * CELL - CELL -CELL) food.x -= CELL;
    if(food.y < 4 * CELL) food.y += CELL;
    if(food.x > COL * CELL - CELL -CELL) food.y -= CELL;

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
bool collisionWithRandomWall(){
    for(auto& p : wall){
        if(SDL_HasIntersection(&p,&head)){
            return true;
        }
    }
    return false;
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
        p_food.first = ramdomCell();
        p_food.second = ramdomCell();
        if(SDL_HasIntersection(&p_food.first,&p_food.second)) makeTLfood();
        if(SDL_HasIntersection(&p_food.first,&head)) makeTLfood();
        if(SDL_HasIntersection(&p_food.second,&head)) makeTLfood();
        setCellState(p_food.first ,2);
        setCellState(p_food.second ,2);

}

bool collisonWithFood(SDL_Rect& food){
    if(SDL_HasIntersection(&head,&food)){
        return true;
    }

    else return false;
}
#if 1

SDL_Rect getRandFoodTextureSrcRect(SDL_Texture *pictures[]){
    int w,h;
    SDL_QueryTexture(pictures[Foodlist],NULL,NULL,&w,&h);
    w/=22;
    int x = rand()%22 * w;
    return SDL_Rect({x,0,w,h});

}
void renderFood(SDL_Texture *pictures[],SDL_Rect src) {
    // Draw foods
    SDL_Rect temp;
    temp = p_food.first;
    temp.x -= 7;
    temp.y -= 9;
    temp.w += 14;
    temp.h += 18;
    SDL_RenderCopy(renderer,pictures[mode == LockMode ? Key : Foodlist],&src,&temp);
    temp = p_food.second;
    temp.x -= 7;
    temp.y -= 9;
    temp.w += 14;
    temp.h += 18;
    SDL_RenderCopy(renderer,pictures[mode == LockMode ? Box : Foodlist],&src,&temp);

}

void renderBoardAndSnake(SDL_Texture *pictures[]) {
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

}
#endif // 0


