#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <bits/stdc++.h>

enum State
{
    STARTMENU,
    INGAME,
    EXIT
};
SDL_Color white{255,255,255,255};
SDL_Color red{179,85,93,255};
SDL_Color green{153,229,80,255};

const int FOOD = 2;
const int COL = 24;
const int ROW = 24;
const int CELL = 40;
const int DELAY = 150;

int delay = DELAY;
SDL_Window* window;
SDL_Renderer* renderer;

SDL_Rect head{ COL * CELL / 6,ROW * CELL / 2,CELL,CELL};
std::deque<SDL_Rect> snake;
int SnakeSize = 3;

SDL_Rect direction{ CELL,0 };

std::vector<SDL_Rect> foods;
std::pair<SDL_Rect,SDL_Rect> telefood;
int FoodsNumber = FOOD;
int FoodsEated = 0;

bool isTouchBounderies = false;
bool isTouchSnakeBody = false;

bool pause = false;


const char* eyePath[13]{
"snakeEye\\snakeEye1.png",
"snakeEye\\snakeEye1.png",
"snakeEye\\snakeEye2.png",
"snakeEye\\snakeEye3.png",
"snakeEye\\snakeEye4.png",
"snakeEye\\snakeEye5.png",
"snakeEye\\snakeEye6.png",
"snakeEye\\snakeEye7.png",
"snakeEye\\snakeEye8.png",
"snakeEye\\snakeEye9.png",
"snakeEye\\snakeEye10.png",
"snakeEye\\snakeEye11.png",
"snakeEye\\snakeEye12.png"
};
