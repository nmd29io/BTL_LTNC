#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <bits/stdc++.h>

enum State{    START,    INGAME,    EXIT };

/***icons enum ***/
enum{Score,Trophy,Option,SpeakerMute,SpeakerOn,flyMode,teleMode,lockMode,wallMode,MusicOn,MusicOff,Icons};

/***pictures enum ***/
enum{StartBg,Food,Head,Body,Tail,Curve,Board,Foodlist,Wall,Key,Box,Pictures};

/***chunks enum***/
enum{Start,Eat,Death,Chunks};bool mute = false;

/***Text enum ***/
enum{Play,Exit,GameOver,GameOver2,Point,Texts};

enum Mode{NormalMode, TeleMode, FlyMode, WallMode, LockMode};Mode mode = NormalMode;
bool soundhasnotplay = true;
bool locking = false;
SDL_Rect text_pos[20];


SDL_Color white{255,255,255,255};
SDL_Color black{0,0,0,255};
SDL_Color red{179,85,93,255};
SDL_Color green{153,229,80,255};

const int COL = 24;
const int ROW = 24;
const int CELL = 40;
const int INIT_SIZE = 3;
const int WallNum = 50;
float FPS = 75;
Uint32 t0,t1,delta;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Point m;
SDL_Rect head;
std::deque<SDL_Rect> snake;
int SnakeSize = INIT_SIZE;
float speed;
std::queue<SDL_Point> q_dir;
SDL_Point dir;



std::pair<SDL_Rect,SDL_Rect> p_food;
SDL_Rect foodsrcRect;

std::vector<SDL_Rect> wall;

bool pause;

int FoodsEated = 0;


void renderAnimation(std::string path,int i, int col, int row, SDL_Rect dst, int angle, SDL_Point* center){

    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL,&w,&h);
    w /= col; h /= row;
    int j = i/col;
    SDL_Rect rect = {i*w,j*h,w,h};
            SDL_RenderCopyEx(renderer,texture,&rect,&dst,angle,center,SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
}





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
