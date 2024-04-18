#pragma once
#include "game.h"
#include "global.h"
enum Dir
{
	RIGHT,LEFT,UP,DOWN
};
std::queue<int> inputQueue;

void getInput(SDL_Event &e, State state){
	while (SDL_PollEvent(&e)) {
                                switch(e.type)
                                {
                                    case SDL_QUIT:
                                        state = EXIT;
                                    break;
                                    case SDL_KEYDOWN:

                                        switch (e.key.keysym.sym)
                                        {

                                            if(inputQueue.back() != UP || inputQueue.back() != DOWN){
                                                case SDLK_UP: pause = false;inputQueue.push(UP);
                                                break;
                                                case SDLK_DOWN:pause = false;inputQueue.push(DOWN);
                                            }

                                            else{
                                                case SDLK_LEFT:pause = false;inputQueue.push(LEFT);
                                                break;
                                                case SDLK_RIGHT:pause = false;inputQueue.push(RIGHT);
                                                break;
                                            }
                                                case SDLK_r:newgame(); lose = false;soundhasnotplay = true;
                                                break;
                                                case SDLK_SPACE:pause = !pause;
                                                break;
                                        }
                                    break;
                                }
    }
}
void getMultipleInput(SDL_Event &e, State state){
    while (SDL_PollEvent(&e)){
        if( e.type == SDL_QUIT )
                    {
                        state = EXIT;
                    }
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if(currentKeyStates[SDL_SCANCODE_UP]) direction.y = -CELL;
        if(currentKeyStates[SDL_SCANCODE_DOWN]) direction.y = CELL;
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) direction.y = CELL;
        if(currentKeyStates[SDL_SCANCODE_LEFT]) direction.y = -CELL;
        delete currentKeyStates;
    }


}
void updateDirection() {
    if(inputQueue.empty() == false){
        switch(inputQueue.front())
        {
        case UP:setDir(0,-CELL);
        break;
        case DOWN:setDir(0,CELL);
        break;
        case RIGHT:setDir(CELL,0);
        break;
        case LEFT:setDir(-CELL,0);
        break;
        }
        inputQueue.pop();
    }
}

void loadNewSegment(){
        head.x += direction.x;
        head.y += direction.y;
        snake.push_front(head);
        if (int(snake.size()) > SnakeSize) { snake.pop_back(); }
}
void handleInGame(SDL_Event e,State state,
                  Mix_Chunk* eatSound, Mix_Chunk* deathSound,
                  SDL_Texture* board,SDL_Texture* foodTexture, SDL_Texture* bodyTexture,SDL_Texture* headTexture,
                  Text &gomeOverText,Text &gomeOverText2,
                  int &frame)
{
                getInput(e,state);

                if(pause)   goto renderPart;

                                updateDirection();
                                loadNewSegment();
                                checkCollisions();
                            if(lose){
                                if(soundhasnotplay){Mix_PlayChannel(-1, deathSound, 0);soundhasnotplay = false;}
                                gomeOverText2.renderText(140,450,white);
                                gomeOverText.renderText(140,450,black);
                            }
                            else{

                                if(collisonWithTLFood()){
                                    Mix_PlayChannel(-1, eatSound, 0);
//                                    delay-=(20/FoodsEated);
                                    makeTLfood();

                                }
                                renderPart:
                                renderGame(board,foodTexture,bodyTexture,headTexture);

                                    auto* eyeTexture = IMG_LoadTexture(renderer, eyePath[frame%13]);
                                    SDL_RenderCopy(renderer,eyeTexture,NULL,&head);
                                    SDL_DestroyTexture(eyeTexture);

                                frame++;
                                }

//                        SDL_RenderCopy(renderer,foodTexture,NULL,&scorePos);
//                        SDL_RenderCopy(renderer,highScoreIconTexture,NULL,&highScorePos);
//                        renderScore(score);
                SDL_RenderPresent(renderer);SDL_Delay(delay);

}
