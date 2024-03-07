
#include <SDL.h>
#include <vector>


const int SCREEN_W = 500;
const int SCREEN_H = 500;
const int TEXTURE_W = 2000;
const int TEXTURE_H = 2000;


int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;

	SDL_Rect source{ TEXTURE_W / 2,TEXTURE_H / 2,SCREEN_W / 8, SCREEN_H / 8 };
	SDL_Rect dest{ 10,10,SCREEN_W - 20, SCREEN_H - 20 };
	SDL_Rect r{ 100,100,10,10 };
	SDL_Event e;
	
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_CreateWindowAndRenderer(SCREEN_W, SCREEN_H,
		SDL_WINDOW_OPENGL, &window, &renderer);
	SDL_SetWindowTitle(window, "HOC SDL");


	texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, TEXTURE_W, TEXTURE_H);


	std::vector<SDL_Point> pv;
	for(int i = 0; i < 10000; i++) {
		pv.push_back({ rand() % TEXTURE_H, rand() % TEXTURE_W });
	}
	bool running = true;
	while (running) {
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT) running = false;

				if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_RIGHT: source.x += 3; break;
					case SDLK_LEFT: source.x -= 3; break;
					case SDLK_UP: source.y -= 3; break;
					case SDLK_DOWN: source.y += 3; break;
					case SDLK_1: source.w *=2; source.h *= 2; break;
					case SDLK_2: source.w /=2; source.h /= 2; break;

					}
				}
			}
			//clear texture
			//
			SDL_SetRenderTarget(renderer, texture);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);

			//move position o dot around
			//
			for (SDL_Point& ap : pv) {
				ap.x += rand() % 3 - 1;
				ap.y += rand() % 3 - 1;
			}
			//draw dots to screen
			//
			
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderDrawPoints(renderer, pv.data(), pv.size());
			//Copy selection from texture to the screen
			//
			SDL_SetRenderTarget(renderer, nullptr);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, texture, &source, &dest);
			SDL_RenderPresent(renderer);
			SDL_Delay(50);
	}

	return 0;
}

