#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<iostream>
#include<vector>
#include<deque>


const int COL = 30;
const int ROW = 20;
const int CELL = 28;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;

SDL_Rect head{ COL * CELL / 2,ROW * CELL / 2,CELL - 1,CELL - 1 };
std::deque<SDL_Rect> snake{ head,{ COL * CELL / 2 - CELL - 1,ROW * CELL / 2,CELL-1,CELL-1 } };
int SnakeSize = 2;

SDL_Rect direction{ CELL,0 };

std::vector<SDL_Rect> foods;
int FoodsNumber = 5;
int countFoodsEated = 0;

bool isTouchBounderies = false;
bool isTouchSnakeBody = false;

bool running = false;
bool Initialize();
void Shutdown();
void Input();

void createFoods();
void updateHead();
void checkCollisions();
void eatFood();
void renderBaseGame();
void renderGameOver();

void renderGameOver(){

}
void createFoods() {
    while (FoodsNumber) {
        foods.push_back({ rand() % COL * CELL,rand() % ROW * CELL ,CELL-1,CELL-1 });
        FoodsNumber--;
    }
}
void updateHead() {
    // Move the snake
    head.x = snake.front().x + direction.x;
    head.y = snake.front().y + direction.y;

    snake.push_front(head);
    if (int(snake.size()) > SnakeSize) { snake.pop_back(); }

}
void checkCollisions() {
    // Check for collisions with snake's body
    for (SDL_Rect& segment : snake) {
        if ((segment.x > head.x - CELL && segment.x < head.x + CELL)
            && (segment.y > head.y - CELL && segment.y < head.y + CELL)
            ) {
            isTouchSnakeBody = true;

            break;
        }
    }

    // Check for collisions with window boundaries
    if (    head.x > COL * CELL - CELL 
        ||  head.y > ROW * CELL - CELL 
        ||  head.x < 0 
        ||  head.y < 0
        ) 
    {
        isTouchBounderies = true;
        direction.x=-direction.x;
        direction.y=-direction.y;

    }
}

void eatFood() {

    for (SDL_Rect& food : foods)
        if ((food.x > head.x - CELL && food.x < head.x + CELL)
            && (food.y > head.y - CELL && food.y < head.y + CELL)
            ) {
            food.x = -CELL; food.y = -CELL; countFoodsEated++;
            
            
            
            //Make snake longer
            SnakeSize += 1;
            foods.push_back({ rand() % COL * CELL,rand() % ROW * CELL ,CELL,CELL });
        }

}
void renderBaseGame() {
    // Clear background /green
    SDL_SetRenderDrawColor(renderer, 150, 200, 50, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw foods /red
    SDL_SetRenderDrawColor(renderer, 255, 20, 20, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& food : foods) {
        //if(food == foods.front() )
        SDL_RenderFillRect(renderer, &food);
    }
    // Draw the snake /blue
    SDL_SetRenderDrawColor(renderer, 60, 100, 220, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& segment : snake) {
        SDL_RenderFillRect(renderer, &segment);

    }
    // Draw snake head detail
    SDL_SetRenderDrawColor(renderer, 20, 20, 220, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &head);
}
void Input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                direction.x = 0; direction.y = -CELL;
                break;
            case SDLK_DOWN:
                direction.x = 0; direction.y = CELL;
                break;
            case SDLK_LEFT:
                direction.x = -CELL; direction.y = 0;
                break;
            case SDLK_RIGHT:
                direction.x = CELL; direction.y = 0;
                break;
            }
        }
    }
}

bool Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() != 0) {
        std::cout << "TTF initialization failed: " << TTF_GetError() << std::endl;
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
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
}

