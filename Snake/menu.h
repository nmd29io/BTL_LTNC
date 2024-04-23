#pragma once
#include "text.h"
#include "game.h"
#include "global.h"

int highScore;

void SaveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}
void LoadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
}
void renderScore(Text* score){
    LoadHighScore();
    if (FoodsEated > highScore) {
            highScore = FoodsEated;
            SaveHighScore();
    }
    score->setText(std::to_string(FoodsEated));
    score->renderText(80,45, white);
    score->setText(std::to_string(highScore));
    score->renderText(235,45, white);
}
bool hoverButton(Text* text,int x,int y, int size,SDL_Event &e){
    SDL_Rect temp;
    text->setFont(size);
                    text->renderText(x,y,white);
                    temp = text->getRect();
                    if(SDL_PointInRect(&m,&temp ) ){
                        text->setFont(size,"font/8-bit Arcade Out.ttf");
                        text->renderText(x,y,black);
                        if(e.type == SDL_MOUSEBUTTONDOWN)return true;
                    }
                    return false;
}

void handleStartMenu(SDL_Event &e, State &state, SDL_Texture* pictures[], Mix_Chunk* chunks[], Text* texts[]){
    SDL_Rect temp;

                while (SDL_PollEvent(&e)) {

                    //render bg
                    SDL_RenderCopy(renderer,pictures[StartBg],NULL,NULL);
                    SDL_GetMouseState(&m.x,&m.y);

                    if (e.type == SDL_QUIT) state = EXIT;

                    //play button
                    else if(hoverButton(texts[Play],400,400,80,e)){Mix_PlayChannel(-1,chunks[Start],0); state = INGAME;}

                    //exit button
                    else if(hoverButton(texts[Exit],430,500,80,e)) state = EXIT;

                }

}
