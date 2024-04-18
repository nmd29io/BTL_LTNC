#pragma once
#include "global.h"
class Text
{
protected:
	SDL_Rect pos;
	std::string text;
	TTF_Font* font;
public:
	SDL_Rect getRect() {return pos;}
	void setText(std::string t){text = t;}
	void setFont( int size,std::string fpath = "font/VT323-Regular.ttf"){
		font = TTF_OpenFont(fpath.c_str(),size);
	}
	void renderText(int x, int y, SDL_Color &color){
		auto* surface = TTF_RenderText_Solid(font,text.c_str(),color);
    	auto* texture = SDL_CreateTextureFromSurface(renderer, surface);

        pos.x = x;
        pos.y = y;
        pos.w = surface->w;
        pos.h = surface->h;
	    SDL_RenderCopy(renderer, texture, NULL, &pos);
	    SDL_FreeSurface(surface);
	    SDL_DestroyTexture(texture);
	}
	void renderText(int x, int y,SDL_Color &color, SDL_Color &bg){
		auto* surface = TTF_RenderText_LCD(font,text.c_str(),color,bg);
    	auto* texture = SDL_CreateTextureFromSurface(renderer, surface);

        pos.x = x;
        pos.y = y;
        pos.w = surface->w;
        pos.h = surface->h;
	    SDL_RenderCopy(renderer, texture, NULL, &pos);
	    SDL_FreeSurface(surface);
	    SDL_DestroyTexture(texture);
	}
	Text(int size,std::string fpath = "font/VT323-Regular.ttf"){
		setFont(size,fpath);
	}
	Text(std::string t,int size,std::string fpath = "font/VT323-Regular.ttf"){
		setText(t);setFont(size,fpath);
	}
	~Text(){
		TTF_CloseFont(font);
	}
};
