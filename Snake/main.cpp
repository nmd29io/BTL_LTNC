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
        //Menu
        auto* menuBg = IMG_LoadTexture(renderer,"picture/menu_bg.jpg");
        Text title("SNAKE",100);
        Text playText("PLAY",80);
        Text exitText("EXIT",80);
        //Music
        auto* clickSound = Mix_LoadMUS("sound/interface/click4.ogg");
        if(Mix_PlayMusic(clickSound, -1) == -1) std::cout<<"load music false";
        //game
        auto* eatSound = Mix_LoadWAV("sound/crunch.wav");
        auto* deathSound = Mix_LoadWAV("sound/death.wav");
        auto* board = IMG_LoadTexture(renderer,"picture/board.png");
        auto* foodTexture = IMG_LoadTexture(renderer, "graphics/food.png");
        auto *bodyTexture = IMG_LoadTexture(renderer, "picture/body.png");
        auto *headTexture = IMG_LoadTexture(renderer, "picture/head.png");
        Text score(36);
        Text gomeOverText("Game Over! Press 'R' to replay.",55);

    State state = STARTMENU;
    SDL_Event event;
    bool quit = false;bool ok = true;
    while(!quit){

        switch(state){
            case STARTMENU:
                handleStartMenu(event,state,menuBg,title,playText,exitText);
                SDL_RenderPresent(renderer);SDL_Delay(50);
            break;
            case INGAME:
                            // input(event,state);

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
                                            newgame(); lose = false;ok = true;
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
                                if(ok){Mix_PlayChannel(-1, deathSound, 0);ok = false;}
                                gomeOverText.renderText(140,450,white);
                            }
                            else{
                            if(collisonWithTeleFood()){
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
                            renderScore(score);
                            SDL_RenderPresent(renderer);SDL_Delay(delay);
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
