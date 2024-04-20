#include "game.h"
#include "menu.h"
#include "text.h"
#include "sdl_setup.h"
#include "ingame.h"

int main(int argc, char** argv)
{
    int frame = 1;
    srand(time(NULL));
    if(!Initialize()) return -1;
    newgame(5,15);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//icons
        SDL_Texture* icons[Icons]; SDL_Rect iconsPos[Icons];
        icons[Score] = IMG_LoadTexture(renderer,"picture/food2.png");iconsPos[Score] = {40,40,40,40};
        icons[Trophy] = IMG_LoadTexture(renderer,"picture/Icons/Trophy.png");iconsPos[Trophy] = {133,40,40,40};
        icons[Option] = IMG_LoadTexture(renderer,"picture/Icons/Option.png");iconsPos[Option] = {900,40,40,40};
        icons[SpeakerOn] = IMG_LoadTexture(renderer,"picture/Icons/SpeakerOn.png");iconsPos[SpeakerOn] = {850,40,40,40};
        icons[SpeakerMute] = IMG_LoadTexture(renderer,"picture/Icons/SpeakerMute.png");iconsPos[SpeakerMute] = {850,40,40,40};
//picture
        SDL_Texture* pictures[Pictures];
        pictures[StartBg] = IMG_LoadTexture(renderer,"picture/startbg.png");
        pictures[Food] = IMG_LoadTexture(renderer,"picture/food2.png");
        pictures[Board] = IMG_LoadTexture(renderer,"picture/board.png");
        pictures[Body] = IMG_LoadTexture(renderer, "picture/shaded_body.png");
//sound
        Mix_Chunk* chunks[Chunks];
        chunks[Start] = Mix_LoadWAV("sound/click.wav");
        chunks[Eat] = Mix_LoadWAV("sound/crunch.wav");
        chunks[Death] = Mix_LoadWAV("sound/death.wav");
//text
        Text* texts[Texts];
        texts[Play] = new Text("start",80);
        texts[Exit] = new Text("exit",80);
        texts[GameOver] = new Text("game over press space to replay",60,"font/8-bit Arcade Out.ttf");
        texts[GameOver2] = new Text("game over press space to replay",60,"font/8-bit Arcade In.ttf");
        texts[Point] = new Text(30,"font/dogicabold.ttf");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    State state = START;
    Mode mode = Normal;
    SDL_Event event;
    bool quit = false;
    while(!quit){
        switch(state){
            case START:
                handleStartMenu(event,state,pictures,chunks,texts);

            break;
            case INGAME:
                handleInGame(event,state,pictures,icons,chunks,texts,frame,iconsPos);

            break;
            case EXIT:
                quit = true;

            break;

        }

	}
    Shutdown();

	return 0;
}
