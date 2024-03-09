#pragma once
#include"SDL.h"
#include<iostream>
#include<vector>
#include<deque>

const int COL = 60;
const int ROW = 40;
const int CELL = 20;

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Rect head{ COL * CELL / 2,ROW * CELL / 2,CELL - 1,CELL - 1 };
std::deque<SDL_Rect> snake{ head,{ COL * CELL / 2 - CELL - 1,ROW * CELL / 2,CELL,CELL } };
int SnakeSize = 2;

SDL_Rect direction{ CELL,0 };

std::vector<SDL_Rect> foods;
int FoodsNumber = 5;
int countFoodsEated = 0;

bool gameOver = false;
bool running = false;
bool Initialize();
void Shutdown();
void processInput();

void createFoods();
void updateHead();
void checkCollisions();
void eatFood();
void render();


void createFoods() {
    while (FoodsNumber) {
        foods.push_back({ rand() % COL * CELL,rand() % ROW * CELL ,CELL,CELL });
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
            gameOver = true;
            break;
        }
    }

    // Check for collisions with window boundaries
    if (head.x > COL * CELL - CELL || head.y > COL * CELL - CELL || head.x < 0 || head.y < 0) {
        gameOver = true;
    }
}
void eatFood() {

    for (SDL_Rect& food : foods)
        if ((food.x > head.x - CELL && food.x < head.x + CELL)
            && (food.y > head.y - CELL && food.y < head.y + CELL)
            ) {
            food.x = -CELL; food.y = -CELL;
            countFoodsEated++;
            //Make snake longer
            SnakeSize += 5;
            foods.push_back({ rand() % COL * CELL,rand() % ROW * CELL ,CELL,CELL });
        }
}
void render() {
    // Green background
    SDL_SetRenderDrawColor(renderer, 150, 200, 50, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw foods
    SDL_SetRenderDrawColor(renderer, 255, 20, 20, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& food : foods) {
        //if(food == foods.front() )
        SDL_RenderFillRect(renderer, &food);
    }
    // Draw the snake /blue
    SDL_SetRenderDrawColor(renderer, 60, 140, 220, SDL_ALPHA_OPAQUE);
    for (SDL_Rect& segment : snake) {
        SDL_RenderFillRect(renderer, &segment);
    }
    SDL_SetRenderDrawColor(renderer, 20, 20, 220, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &head);



    SDL_RenderPresent(renderer);
    SDL_Delay(50);
}
void processInput() {
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
    //if (TTF_Init() != 0) {
    //    std::cout << "TTF initialization failed: " << TTF_GetError() << std::endl;
    //    return false;
    //}
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
    SDL_Quit();
    //TTF_Quit();
}

