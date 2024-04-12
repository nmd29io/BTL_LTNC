#pragma once
#include<string>
#include"game.h"
#include"menu.h"
#include <fstream>
bool StartMenu = true;

int highScore_;
SDL_Rect startButton, quitButton;
SDL_Surface *textSurface;
TTF_Font *font;
SDL_Color* color;
void renderQuit(SDL_Color Color){
    font = TTF_OpenFont("D:\\Project1\\VT323\\VT323-Regular.ttf",CELL*2);
    
    textSurface = TTF_RenderText_Solid(font,"Quit", Color);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);

        quitButton.x = (CELL*COL - textSurface->w) / 2 ;
        quitButton.y = (CELL*ROW - textSurface->h) / 2 + textSurface->h;
        quitButton.w = textSurface->w;
        quitButton.h = textSurface->h;
    SDL_RenderCopy(renderer, texture, NULL, &quitButton);

}
void renderStartMenu(SDL_Color Color){
    font = TTF_OpenFont("D:\\Project1\\VT323\\VT323-Regular.ttf",CELL*2);
    

    textSurface = TTF_RenderText_Solid(font,"START", Color);

        startButton.x = (CELL*COL - textSurface->w) / 2;
        startButton.y = (CELL*ROW - textSurface->h) / 2;
        startButton.w = textSurface->w;
        startButton.h = textSurface->h;

    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, texture, NULL, &startButton);
}
void gameOver(){
	auto* font = TTF_OpenFont("D:\\Project1\\VT323\\VT323-Regular.ttf",1.5*CELL - 4);
	SDL_Color textColor = { 255, 255, 255,255};

	textSurface = TTF_RenderText_Solid(font,"Game Over! Press 'R' to replay.", textColor);
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
    textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
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
