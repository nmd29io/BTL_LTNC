#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>
#include<vector>
#include<deque>
const int FOOD = 2;
const int COL = 24;
const int ROW = 18;
const int CELL = 44;
int delay = 150;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;

SDL_Rect wall{CELL,CELL,COL * CELL - 2*CELL,ROW * CELL - 2*CELL};
SDL_Rect head{ COL * CELL / 6,ROW * CELL / 2,CELL-1,CELL-1};
std::deque<SDL_Rect> snake;
int SnakeSize = 3;

SDL_Rect direction{ CELL,0 };

std::vector<SDL_Rect> foods;
int FoodsNumber = FOOD;
int FoodsEated = 0;

bool isTouchBounderies = false;
bool isTouchSnakeBody = false;

bool running = false;
bool pause = true;
void initSnake(){
    snake.resize(3);
    SnakeSize = 3;
    for (int i = 0; i < SnakeSize; ++i) {
        snake[i].x = CELL*(COL/6 -i);
        snake[i].y = CELL*(ROW/2 -i);
    }
}
void createFoods() {
    while (FoodsNumber) {
        foods.push_back({ rand() % (COL-2) * CELL + CELL, rand() % (ROW-2) * CELL + CELL , CELL, CELL});
        FoodsNumber--;
    }
}bool lose =false;
void makeTLfood();
void replay(){
    delay = 150;
    lose =false;
    snake.clear();
    foods.clear();
    FoodsNumber=FOOD;
    FoodsEated =0;
    direction.x=CELL;direction.y=0;
    makeTLfood();
    initSnake();
}
// //body texture
// enum{    bl,br,tl,tr,h,v    };
// std::deque<string> bodyTex[6]{
//     bodyTex[bl] = "D:\\Project1\\Project1\\Graphics\\body_bl.png"
//     bodyTex[br] = "D:\\Project1\\Project1\\Graphics\\body_br.png"
//     bodyTex[tl] = "D:\\Project1\\Project1\\Graphics\\body_tl.png"
//     bodyTex[tr] = "D:\\Project1\\Project1\\Graphics\\body_tr.png"
//     bodyTex[h] = "D:\\Project1\\Project1\\Graphics\\body_horizontal.png"
//     bodyTex[v] = "D:\\Project1\\Project1\\Graphics\\body_vertical.png"
// }
// texture = IMG_LoadTexture(renderer,bodyTex[h]);
// std::deque<SDL_Texture> snakeBodyTexture{texture};
// void decideBodyTex(){
//     if(snakeBodyTexture.front() =)
// }
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
        if (snake[0].x == snake[i].x && snake[0].y ==snake[i].y
            ) {
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
// Mix_Chunk* eatSound = Mix_LoadWAV("D:\\Project1\\crunch.wav");
std::pair<SDL_Rect,SDL_Rect> telefood;

void makeTLfood(){
        telefood.first = {rand() % (COL-2) * CELL + CELL, rand() % (ROW-2) * CELL + CELL ,CELL-1,CELL-1};
        telefood.second = {rand() % (COL-2) * CELL + CELL, rand() % (ROW-2) * CELL + CELL ,CELL-1,CELL-1};
}

bool tele(){
    if(head.x == telefood.first.x && head.y == telefood.first.y){
        FoodsEated++;snake.push_front(telefood.second);return true;
    }
    else if(head.x == telefood.second.x && head.y == telefood.second.y){
        FoodsEated++;snake.push_front(telefood.first);return true;
    }
    else return false;
}
void eatFood() {

    for (SDL_Rect& food : foods)
        for(SDL_Rect& segment : snake)
            if ((food.x > segment.x - CELL && food.x < segment.x + CELL)
                && (food.y > segment.y - CELL && food.y < segment.y + CELL)
                ) 
            {
                // Mix_PlayChannel(-1, eatSound, 0);
                food.x = -CELL; food.y = -CELL; FoodsEated++;
                
                //Make snake longer
                SnakeSize += 1;
                //Increase speed
                delay-=(20/FoodsEated);
                //Add food
            foods.push_back({ rand() % (COL-2) * CELL + CELL, rand() % (ROW-2) * CELL + CELL , CELL, CELL});


            }

}
void renderBaseGame() {
    // Clear background /green
    SDL_SetRenderDrawColor(renderer, 150, 200, 50, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw foods /red
    texture = IMG_LoadTexture(renderer, "D:\\Project1\\food.png"); 
    for (SDL_Rect& food : foods) {
        SDL_RenderCopy(renderer,texture,NULL,&food);
    }
    SDL_RenderCopy(renderer,texture,NULL,&telefood.first);
    SDL_RenderCopy(renderer,texture,NULL,&telefood.second);
    // Draw the snake /blue
    SDL_SetRenderDrawColor(renderer, 60, 100, 220, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& segment : snake) {
        SDL_RenderFillRect(renderer, &segment);

    }
    // Draw snake head detail
    SDL_SetRenderDrawColor(renderer, 20, 20, 220, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &head);
    // Draw wall
    SDL_SetRenderDrawColor(renderer, 20, 20, 220, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer,&wall);
}

bool Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() != 0) {
        std::cout << "TTF initialization failed: " << TTF_GetError() << std::endl;
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Mix initialization failed: " << Mix_GetError() << std::endl;
        return false;
    }
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags) {
        std::cout << "IMG initialization failed : " << IMG_GetError();
    }
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        COL * CELL, ROW * CELL, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    running = true;
    return true;
}

void Shutdown() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyTexture(texture);
    texture = NULL;

    // Mix_FreeChunk(eatSound);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    Mix_CloseAudio();
}
