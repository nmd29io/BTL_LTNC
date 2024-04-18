#include "game.h"
#include "menu.h"
#include "text.h"
#include "sdl_setup.h"
#include "input.h"

int main(int argc, char** argv)
{

int frame = 1;

    Initialize();


    initSnake();
    srand(time(NULL));
    makeTLfood();

        //Start
        auto* startbg = IMG_LoadTexture(renderer,"picture/startbg.jpg");
        Text title("SNAKE",100);
        Text playText("PLAY",80);
        Text exitText("EXIT",80);
        //Music
        auto* clickSound = Mix_LoadWAV("sound/click.wav");
        //menu
        SDL_Rect scorePos{40,40,40,40};
        auto* highScoreIconTexture = IMG_LoadTexture(renderer,"picture/Icons/Trophy.png");
        SDL_Rect highScorePos{130,40,40,40};
        SDL_Texture* menu[ID];

        Text score(30,"font/dogicabold.ttf");
//        menu[SCORE] = IMG_LoadTexture(renderer,)

        //game
//        auto* upSound = Mix_LoadWAV("sound/   ");
//        auto* downSound = Mix_LoadWAV("sound/   ");
//        auto* rightSound = Mix_LoadWAV("sound/   ");
//        auto* leftSound = Mix_LoadWAV("sound/   ");
        auto* eatSound = Mix_LoadWAV("sound/crunch.wav");
        auto* deathSound = Mix_LoadWAV("sound/death.wav");
        auto* board = IMG_LoadTexture(renderer,"picture/board2.png");
        auto* foodTexture = IMG_LoadTexture(renderer, "picture/food2.png");
        auto *bodyTexture = IMG_LoadTexture(renderer, "picture/shaded_body.png");
        auto *headTexture = IMG_LoadTexture(renderer, "picture/shaded_head.png");

        Text gomeOverText("Game Over Press R to replay",55,"font/8-bit Arcade Out.ttf");
        Text gomeOverText2("Game Over Press R to replay",55,"font/8-bit Arcade In.ttf");

    State state = START;
    SDL_Event event;
    bool quit = false;
    while(!quit){

        switch(state){
            case START://Menu.h
                handleStartMenu(event,state,startbg,title,playText,exitText,clickSound);
                SDL_RenderPresent(renderer);SDL_Delay(50);
            break;
            case INGAME://Game.h
                            #if 0
                            handleInGame(event,state,
                                         eatSound,deathSound,
                                         board,foodTexture,bodyTexture,headTexture,
                                         gomeOverText,gomeOverText2,
                                         frame);
                            #endif
                            #if 1
                            while (SDL_PollEvent(&event))
                            {
                                switch(event.type)
                                {
                                    case SDL_QUIT:
                                        quit = true;
                                    break;
                                    case SDL_KEYDOWN:

                                        switch (event.key.keysym.sym) {
                                        case SDLK_UP:pause = false;
                                            if(direction.y == 0)
                                            {direction.x = 0; direction.y = -CELL;}
                                            break;
                                        case SDLK_DOWN:pause = false;
                                            if(direction.y == 0)
                                            {direction.x = 0; direction.y = CELL;}
                                            break;
                                        case SDLK_LEFT:pause = false;
                                            if(direction.x == 0)
                                            {direction.x = -CELL; direction.y = 0;}
                                            break;
                                        case SDLK_RIGHT:pause = false;
                                            if(direction.x == 0)
                                            {direction.x = CELL; direction.y = 0;}
                                            break;
                                        case SDLK_SPACE:
                                            pause = !pause;
                                            break;
                                        case SDLK_r:
                                            newgame(); lose = false;soundhasnotplay = true;
                                            break;
                                        }
                                    break;

                                }
                            }

                            if(pause){
                                goto here;

                            }
                            updateHead();
                            checkCollisions();
                            here:
                            if(lose){
                                if(soundhasnotplay){Mix_PlayChannel(-1, deathSound, 0);soundhasnotplay = false;}
                                gomeOverText2.renderText(140,450,white);
                                gomeOverText.renderText(140,450,black);

                            }
                            else{
                            if(collisonWithTLFood()){
                                Mix_PlayChannel(-1, eatSound, 0);
                                delay-=(20/FoodsEated);
                                makeTLfood();

                            }
                            renderGame(board,foodTexture,bodyTexture,headTexture);

                                auto* eyeTexture = IMG_LoadTexture(renderer, eyePath[frame%13]);
                                SDL_RenderCopy(renderer,eyeTexture,NULL,&head);
                                SDL_DestroyTexture(eyeTexture);

                            frame++;
                            }

                            SDL_RenderCopy(renderer,foodTexture,NULL,&scorePos);
                            SDL_RenderCopy(renderer,highScoreIconTexture,NULL,&highScorePos);
                            renderScore(score);
                            SDL_RenderPresent(renderer);SDL_Delay(delay);
                            #endif
            break;
            case EXIT:
                quit = true;
            break;
        }

    }
    Mix_FreeChunk(eatSound);
    Shutdown();


	return 0;
}
