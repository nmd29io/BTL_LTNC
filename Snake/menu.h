#pragma once
#include "text.h"
#include "game.h"
#include "global.h"

bool StartMenu = true;

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
void renderScore(Text &score){
    LoadHighScore();
    if (FoodsEated > highScore) {
            highScore = FoodsEated;
            SaveHighScore();
    }
    std::string scoreText = "" + std::to_string(FoodsEated)+"  "+std::to_string(highScore);
    score.setText(scoreText);
    score.renderText(80,45, white);
}

void handleStartMenu(SDL_Event &e, State &state, SDL_Texture* menuBg, Text &title, Text &playText, Text &exitText, Mix_Chunk* clickSound){

                while (SDL_PollEvent(&e)) {
                    SDL_RenderCopy(renderer,menuBg,NULL,NULL);
                    if (e.type == SDL_QUIT) state = EXIT;
                    //game title
                    title.renderText(420,300,white);
                    //play
                    if(isInRect(e.motion.x,e.motion.y,playText.getRect())) {
                        playText.renderText(420,420,green,red);
                        if(e.type == SDL_MOUSEBUTTONDOWN){Mix_PlayChannel(-1,clickSound,0); state = INGAME;}
                    }
                    else{
                        playText.renderText(420,420,white);
                    }
                    //exit
                    if(isInRect(e.motion.x,e.motion.y,exitText.getRect())) {
                        exitText.renderText(420,500,green,red);
                        if(e.type == SDL_MOUSEBUTTONDOWN) state = EXIT;
                    }
                    else{
                        exitText.renderText(420,500,white);
                    }
                }
}
