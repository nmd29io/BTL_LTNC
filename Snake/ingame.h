#pragma once
#include "game.h"
#include "global.h"
Uint32 t0,delta;

void handleInGame(SDL_Event &e, State &state, SDL_Texture* pictures[], SDL_Texture* icons[], Mix_Chunk* chunks[], Text* texts[], int &frame, SDL_Rect* iconsPos)
{
                            t0 = SDL_GetTicks();

                            while (SDL_PollEvent(&e))
                            {
                                switch(e.type)
                                {
                                    case SDL_QUIT:
                                        state = EXIT;
                                    break;
                                    case SDL_KEYDOWN:
                                        switch (e.key.keysym.sym)
                                        {
                                                case SDLK_UP:
                                                    q_dir.push({0,-CELL});
                                                    break;
                                                case SDLK_DOWN:
                                                    q_dir.push({0,CELL});
                                                    break;
                                                case SDLK_LEFT:
                                                    q_dir.push({-CELL,0});
                                                    break;
                                                case SDLK_RIGHT:
                                                    q_dir.push({CELL,0});
                                                    break;
                                                //WASD
                                                case SDLK_w:
                                                    q_dir.push({0,-CELL});
                                                    break;
                                                case SDLK_s:
                                                    q_dir.push({0,CELL});
                                                    break;
                                                case SDLK_a:
                                                    q_dir.push({-CELL,0});
                                                    break;
                                                case SDLK_d:
                                                    q_dir.push({CELL,0});
                                                    break;
                                                //pause
                                                case SDLK_SPACE:
                                                    pause = !pause;
                                                    break;
                                                //newgame
                                                case SDLK_r:
                                                    newgame(5,15); lose = false;soundhasnotplay = true;
                                                    break;
                                                case SDLK_m:
                                                    if(mute){
                                                            Mix_Volume(0,MIX_MAX_VOLUME);mute = false;
                                                    }
                                                    else{
                                                        Mix_Volume(0,0); mute = true;
                                                    }
                                                    break;
                                        }
                                    break;
                                    default:

                                        if(e.type == SDL_MOUSEBUTTONDOWN){
                                            SDL_GetMouseState(&m.x,&m.y);
                                            if(SDL_PointInRect(&m,&iconsPos[SpeakerOn]) ){
                                                    if(mute){
                                                            Mix_Volume(0,MIX_MAX_VOLUME);mute = false;
                                                    }
                                                    else{
                                                        Mix_Volume(0,0); mute = true;
                                                    }
                                            }
                                            else if(SDL_PointInRect(&m,&iconsPos[Option]) ){
                                                    pause = !pause;
                                            }
                                            else if(pause){
                                                if(SDL_PointInRect(&m,&text_pos[1])){
                                                        newgame(5,15);
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[2])){
                                                        pause = false;
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[3])){
                                                        mode = Tele;
                                                        newgame(5,15);

//                                                            for(int i = 0; i < 24; i++){
//                                                                    for(int j = 0; j < 24; j++){
//                                                                        std::cout << cellState[i][j]<<" ";
//                                                                    }std::cout<<std::endl;
//
//                                                            }std::cout<<std::endl;

                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[4])){
                                                        mode = Normal;
                                                        newgame(5,15);
                                                }
                                            }
                                        }
                                    break;
                                }
                            }
                            //update
                            if (!q_dir.empty()) {
                                    if((dir.x!=q_dir.front().x && dir.y!=q_dir.front().y)
                                       ||(dir.x == 0 && dir.y == 0 && q_dir.front().x != -CELL))
                                        dir = q_dir.front();
                                    q_dir.pop();
                            }
                            updateHead();
                            if(checkCollisions()) lose = true;
                            //running
                            if(!lose && !pause){

                                if(collisonWithTLFood()){
                                    Mix_PlayChannel(-1, chunks[Eat], 0);
                                    if(mode == Tele) makeTLfood();else telefood.first = ramdomCell();


                                }
                                updateSnake();
                            }

                            {//render game
                                renderGame(pictures);
                                auto* eyeTexture = IMG_LoadTexture(renderer, eyePath[frame%13]);
                                SDL_RenderCopy(renderer,eyeTexture,NULL,&snake[0]);
                                SDL_DestroyTexture(eyeTexture);
                                frame++;
                            //score
                                SDL_RenderCopy(renderer,icons[Score],NULL,&iconsPos[Score]);
                                SDL_RenderCopy(renderer,icons[Trophy],NULL,&iconsPos[Trophy]);
                                renderScore(texts[Point]);
                            }
                            if(lose){
                                texts[GameOver2]->renderText(50,200,white);
                                texts[GameOver]->renderText(50,200,black);
                                if(soundhasnotplay){Mix_PlayChannel(-1, chunks[Death], 0);soundhasnotplay = false;}
                            }
                            if(pause) {
                                SDL_SetRenderDrawColor(renderer,0,0,0,200);
                                SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
                                SDL_RenderFillRect(renderer,NULL);
                                Text temp(50);
                                temp.setText("new game");
                                temp.renderText(400,350,white);text_pos[1] = temp.getRect();
                                temp.setText("resume");
                                temp.renderText(400,400,white);text_pos[2] = temp.getRect();
                                temp.setText("tele mode");
                                temp.renderText(400,450,white);text_pos[3] = temp.getRect();
                                temp.setText("normal mode");
                                temp.renderText(400,500,white);text_pos[4] = temp.getRect();

                            }


                            mute ? SDL_RenderCopy(renderer,icons[SpeakerMute],NULL,&iconsPos[SpeakerMute])
                                    :SDL_RenderCopy(renderer,icons[SpeakerOn],NULL,&iconsPos[SpeakerOn]);
                            SDL_RenderCopy(renderer,icons[Option],NULL,&iconsPos[Option]);

                            //present

                                SDL_RenderPresent(renderer);

                                delta = SDL_GetTicks() - t0;
                                if(delta < 1000.0f / FPS )
                                    SDL_Delay(1000.0f / FPS - delta);

}
