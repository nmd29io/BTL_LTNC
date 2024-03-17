#pragma once
#include<string>
#include"game.h"
#include"menu.h"
#include"button.h"

void gameOver(){

	// texture = IMG_LoadTexture(renderer, "D:\\Project1\\istockphoto-1326959978-640x640.jpg");
	// SDL_RenderCopy(renderer, texture,NULL,NULL);

	auto* font = TTF_OpenFont("D:\\Project1\\pixel-gaming-font\\PixelGamingRegular-d9w0g.ttf",40);
	SDL_Color textColor = { 255, 255, 255,255};

	auto *textSurface = TTF_RenderText_Solid(font,"Game Over! Press 'R' to replay.", textColor);
	SDL_Rect textRect;
        textRect.x = (CELL*COL - textSurface->w) / 2;
        textRect.y = (CELL*ROW - textSurface->h) / 2;
        textRect.w = textSurface->w;
        textRect.h = textSurface->h;
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_RenderCopy(renderer, texture, NULL, &textRect);

}

