#pragma once
#include "game.h"
#include "global.h"

Uint32 updateInputDelta,renderDelta,eyeDelta;
void handleInGame(SDL_Event &e, State &state, SDL_Texture* pictures[], SDL_Texture* icons[], Mix_Chunk* chunks[], Text* texts[], int &frame, SDL_Rect* iconsPos){
                        updateInputDelta += t1-t0;

                        if(updateInputDelta > 1000.0f / speed){updateInputDelta = 0;
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
                                                case SDLK_ESCAPE:
                                                case SDLK_SPACE:
                                                    pause = !pause;
                                                    break;
                                                //newgame
                                                case SDLK_r:
                                                    newgame(5,15); lose = false;soundhasnotplay = true;
                                                    break;
                                                case SDLK_m:
                                                    if(mute && Mix_PausedMusic()){
                                                            Mix_Volume(0,MIX_MAX_VOLUME);mute = false;
                                                            Mix_ResumeMusic();
                                                    }
                                                    else{
                                                        Mix_Volume(0,0); mute = true;Mix_PauseMusic();
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
                                            }if(SDL_PointInRect(&m,&iconsPos[MusicOn]) ){
                                                    Mix_PausedMusic() ? Mix_ResumeMusic() : Mix_PauseMusic();
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
                                                        mode = NormalMode;
                                                        newgame(5,15);
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[4])){
                                                        mode = TeleMode;
                                                        newgame(5,15);
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[5])){
                                                        mode = FlyMode;
                                                        newgame(5,15);
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[6])){
                                                        mode = WallMode;
                                                        newgame(5,15);
                                                }
                                                else if(SDL_PointInRect(&m,&text_pos[7])){
                                                        mode = LockMode;
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
                            //check lose
                            if(checkCollisions() || collisionWithRandomWall()
                               || (collisonWithFood(p_food.second)&&locking)) lose = true;
                            //running
                            if(!lose && !pause){
                                updateSnake();
                            }
                            //check eat
                            if(collisonWithFood(p_food.first) && !lose){
                                    if(speed<20)speed += 0.2;
                                    foodsrcRect = getRandFoodTextureSrcRect(pictures);

                                    Mix_PlayChannel(-1, chunks[Eat], 0);
                                    if(mode == TeleMode){
                                        head = p_food.second;
                                        makeTLfood();
                                    }
                                    else if( mode == WallMode){
                                        p_food.first = ramdomCell();
                                        if(wall.size() < WallNum) wall.push_back(ramdomCell());

                                    }

                                    else{
                                            p_food.first = ramdomCell();
                                            fdir = ramdomDir();
                                    }
                                    if(mode == LockMode) {
                                            locking = false;p_food.first = {};
                                    }
                                    else{
                                        FoodsEated++;SnakeSize ++;updateSnake();
                                    }
                            }
                            if(collisonWithFood(p_food.second) && !lose){
                                    Mix_PlayChannel(-1, chunks[Eat], 0);
                                    if(mode == TeleMode){
                                        head = p_food.first;
                                        makeTLfood();FoodsEated++;SnakeSize ++;updateSnake();
                                    }
                                    if(mode == LockMode){
                                        if(locking == false){
                                                makeTLfood();
                                                locking = true;
                                                FoodsEated++;SnakeSize ++;updateSnake();
                                        }
                                    }



                            }
                        }

//render game>
                        renderDelta += t1-t0;
                        if(renderDelta > FPS){renderDelta=0;


                            if(!lose &&mode == FlyMode && (dir.x != 0 || dir.y != 0)) flyFood(p_food.first);
                            renderBoardAndSnake(pictures);
                            renderFood(pictures,foodsrcRect);
                            if(mode == WallMode && wall.empty() == false){
                                for(auto& p : wall){
                                    SDL_RenderCopy(renderer,pictures[Wall],NULL,&p);
                                }
                            }

                            eyeDelta += t1 - t0;
                            if(eyeDelta > 1000.0f / 12){eyeDelta=0;
                                frame++;
                            }

                            auto* eyeTexture = IMG_LoadTexture(renderer, eyePath[frame%13]);
                            SDL_RenderCopy(renderer,eyeTexture,NULL,&snake[0]);
                            SDL_DestroyTexture(eyeTexture);
                            switch(mode){
                                case FlyMode:SDL_RenderCopy(renderer,icons[flyMode],NULL,&iconsPos[flyMode]);break;
                                case TeleMode:SDL_RenderCopy(renderer,icons[teleMode],NULL,&iconsPos[teleMode]);break;
                                case WallMode:SDL_RenderCopy(renderer,icons[wallMode],NULL,&iconsPos[wallMode]);break;
                                case LockMode:SDL_RenderCopy(renderer,icons[lockMode],NULL,&iconsPos[lockMode]);break;
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
                                temp.setText("normal mode");
                                temp.renderText(400,450,white);text_pos[3] = temp.getRect();

                                temp.setText("tele mode");
                                temp.renderText(400,500,white);text_pos[4] = temp.getRect();

                                temp.setText("fly mode");
                                temp.renderText(400,550,white);text_pos[5] = temp.getRect();

                                temp.setText("Wall mode");
                                temp.renderText(400,600,white);text_pos[6] = temp.getRect();

                                temp.setText("Lock mode");
                                temp.renderText(400,650,white);text_pos[7] = temp.getRect();

                            }
                            //icon
                            mute ? SDL_RenderCopy(renderer,icons[SpeakerMute],NULL,&iconsPos[SpeakerMute])
                                    :SDL_RenderCopy(renderer,icons[SpeakerOn],NULL,&iconsPos[SpeakerOn]);
                            Mix_PausedMusic() ?  SDL_RenderCopy(renderer,icons[MusicOff],NULL,&iconsPos[MusicOff])
                                    :SDL_RenderCopy(renderer,icons[MusicOn],NULL,&iconsPos[MusicOn]);
                            SDL_RenderCopy(renderer,icons[Option],NULL,&iconsPos[Option]);
                            //score
                                SDL_RenderCopy(renderer,icons[Score],NULL,&iconsPos[Score]);
                                SDL_RenderCopy(renderer,icons[Trophy],NULL,&iconsPos[Trophy]);
                                renderScore(texts[Point]);
                        }



}
