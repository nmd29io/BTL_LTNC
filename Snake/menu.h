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
void handleStartMenu(SDL_Event &e, State &state, SDL_Texture* pictures[], Mix_Chunk* chunks[], Text* texts[]){
    SDL_Rect temp;

                while (SDL_PollEvent(&e)) {


                    SDL_RenderCopy(renderer,pictures[StartBg],NULL,NULL);

                    if (e.type == SDL_QUIT) state = EXIT;
                    SDL_GetMouseState(&m.x,&m.y);
                    //play
                    texts[Play]->setFont(80);
                    texts[Play]->renderText(400,400,white);
                    temp = texts[Play]->getRect();
                    if(SDL_PointInRect(&m,&temp ) ){
                        texts[Play]->setFont(80,"font/8-bit Arcade Out.ttf");
                        texts[Play]->renderText(400,400,black);
                        if(e.type == SDL_MOUSEBUTTONDOWN){Mix_PlayChannel(-1,chunks[Start],0); state = INGAME;}
                    }
                    //exit
                    texts[Exit]->setFont(80);
                    texts[Exit]->renderText(430,500,white);
                    temp = texts[Exit]->getRect();
                    if(SDL_PointInRect(&m,&temp ) ){
                        texts[Exit]->setFont(80,"font/8-bit Arcade Out.ttf");
                        texts[Exit]->renderText(430,500,black);
                        if(e.type == SDL_MOUSEBUTTONDOWN) state = EXIT;
                    }
                }

}
