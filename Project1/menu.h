#pragma once
#include<string>
#include"game.h"
#include"menu.h"
#include <fstream>

int highScore_;


void gameOver(){
    // SDL_SetRenderDrawColor(0,0,0,255);

    // SDL_RenderFillRect(renderer,)
    
	auto* font = TTF_OpenFont("D:\\Project1\\VT323\\VT323-Regular.ttf",CELL - 4);
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
void SaveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore_;
        file.close();
    }
}
void LoadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore_;
        file.close();
    }
}
void score(){
	LoadHighScore();
	if (FoodsEated > highScore_) {
            highScore_ = FoodsEated;
            SaveHighScore();
    }
	auto* font = TTF_OpenFont("D:\\Project1\\VT323\\VT323-Regular.ttf",CELL - 4);


	SDL_Color textColor = {200, 255, 255, 255}; 
    std::string scoreText = "press space to pause     Score: " + std::to_string(FoodsEated)+"   High score: "+std::to_string(highScore_);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    SDL_Rect textRect;
    textRect.x = (CELL*COL - textWidth) / 2;
    textRect.y = 0;
    textRect.w = textWidth;
    textRect.h = textHeight;

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

}
