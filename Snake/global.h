#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <bits/stdc++.h>

enum State{    START,    INGAME,    EXIT};
/***icons enum ***/
enum{Score,Trophy,Option,SpeakerMute,SpeakerOn,Icons};
/***pictures enum ***/
enum{StartBg,Food,Head,Body,Tail,Curve,Board,Pictures};
/***chunks enum***/
enum{Start,Eat,Death,Chunks};bool mute = false;
/***Text enum ***/
enum{Play,Exit,GameOver,GameOver2,Point,Texts};

enum Mode{Normal, Tele };Mode mode = Normal;
bool soundhasnotplay = true;
SDL_Rect text_pos[20];


SDL_Color white{255,255,255,255};
SDL_Color black{0,0,0,255};
SDL_Color red{179,85,93,255};
SDL_Color green{153,229,80,255};

const int COL = 24;
const int ROW = 24;
const int CELL = 40;
const int INIT_SIZE = 3;
const int INIT_DELAY = 120;
int delay = INIT_DELAY;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Point m;
SDL_Rect head;
std::deque<SDL_Rect> snake;
int SnakeSize = INIT_SIZE;

std::queue<SDL_Point> q_dir;
SDL_Point dir{ CELL,0 };



int FoodsEated = 0;
int cellState[24][24]={
{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};



SDL_Rect food;
std::pair<SDL_Rect,SDL_Rect> telefood;

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
