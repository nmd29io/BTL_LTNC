#pragma once

#include"game.h"
#include"menu.h"
#include"button.h"

#include<cmath>

enum ButtonState {NORMAL, HOVER, PRESSED};

auto renderCircle(SDL_Point pos, Uint8 radius){
	std::vector<SDL_Point> circle;
    for(Uint8 i = pos.x - radius; i <= pos.x + radius; i++){
        for(Uint8 j = pos.y - radius; j <= pos.y + radius; j++){
            if(pow(i-pos.x,2) + pow(j-pos.y,2) - radius*radius < 0.0001){
                circle.push_back({i,j});
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for(SDL_Point& p : circle){
        SDL_RenderDrawPoint(renderer, p.x, p.y);
    }return circle;
    
}
void renderButton(){
	//renderCircle({60,60},55);
	renderCircle({100,60},55);
}