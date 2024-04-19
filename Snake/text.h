#pragma once
#include "global.h"
class Text
{
protected:
	SDL_Rect pos;
	std::string text = "ditme";
	TTF_Font* font;
public:
	SDL_Rect getRect() {return pos;}
	void setText(std::string t){text = t;}
	void setFont( int size,std::string fpath = "font/8-bit Arcade In.ttf"){
		font = TTF_OpenFont(fpath.c_str(),size);
	}
	void renderText(int x, int y, SDL_Color &color){
		auto* surface = TTF_RenderText_Solid(font,text.c_str(),color);
    	auto* texture = SDL_CreateTextureFromSurface(renderer, surface);
    	SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
        pos.x = x;
        pos.y = y;
	    SDL_RenderCopy(renderer, texture, NULL, &pos);
	    SDL_FreeSurface(surface);
	    SDL_DestroyTexture(texture);
	}
	void renderText(int x, int y,SDL_Color &color, SDL_Color &bg){
		auto* surface = TTF_RenderText_LCD(font,text.c_str(),color,bg);
    	auto* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture,NULL,NULL,&pos.w,&pos.h);
        pos.x = x;
        pos.y = y;
	    SDL_RenderCopy(renderer, texture, NULL, &pos);
	    SDL_FreeSurface(surface);
	    SDL_DestroyTexture(texture);
	}
	Text(){}
	Text(int size,std::string fpath = "font/8-bit Arcade In.ttf"){
		setFont(size,fpath);

	}
	Text(std::string t,int size,std::string fpath = "font/8-bit Arcade In.ttf"){
	    setText(t);setFont(size,fpath);
	}
	~Text(){
		TTF_CloseFont(font);
	}
};
