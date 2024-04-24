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
        icons[flyMode] = IMG_LoadTexture(renderer,"picture/flyMode.png");iconsPos[flyMode] = {450,30,60,60};
        icons[teleMode] = IMG_LoadTexture(renderer,"picture/teleMode.png");iconsPos[teleMode] = {450,30,60,60};
        icons[lockMode] = IMG_LoadTexture(renderer,"picture/key.png");iconsPos[lockMode] = {450,30,60,60};
        icons[wallMode] = IMG_LoadTexture(renderer,"picture/wall2.png");iconsPos[wallMode] = {450,30,60,60};


        icons[Score] = IMG_LoadTexture(renderer,"picture/food2.png");iconsPos[Score] = {40,40,40,40};
        icons[Trophy] = IMG_LoadTexture(renderer,"picture/Icons/Trophy.png");iconsPos[Trophy] = {200,40,40,40};
        icons[Option] = IMG_LoadTexture(renderer,"picture/Icons/Option.png");iconsPos[Option] = {900,40,40,40};
        icons[MusicOn] = IMG_LoadTexture(renderer,"picture/Icons/MusicNotes.png");iconsPos[MusicOn] = {800,40,40,40};
        icons[MusicOff] = IMG_LoadTexture(renderer,"picture/Icons/MusicOff.png");iconsPos[MusicOff] = {800,40,40,40};
        icons[SpeakerOn] = IMG_LoadTexture(renderer,"picture/Icons/SpeakerOn.png");iconsPos[SpeakerOn] = {850,40,40,40};
        icons[SpeakerMute] = IMG_LoadTexture(renderer,"picture/Icons/SpeakerMute.png");iconsPos[SpeakerMute] = {850,40,40,40};
//picture
        SDL_Texture* pictures[Pictures];
        pictures[Key] = IMG_LoadTexture(renderer,"picture/key.png");
        pictures[Box] = IMG_LoadTexture(renderer,"picture/box.png");
        pictures[Wall] = IMG_LoadTexture(renderer,"picture/wall.png");
        pictures[Foodlist] = IMG_LoadTexture(renderer,"picture/foodlist.png");
            foodsrcRect = getRandFoodTextureSrcRect(pictures);
        pictures[StartBg] = IMG_LoadTexture(renderer,"picture/startbg.png");
        pictures[Food] = IMG_LoadTexture(renderer,"picture/food2.png");
        pictures[Board] = IMG_LoadTexture(renderer,"picture/board.png");
        pictures[Body] = IMG_LoadTexture(renderer, "picture/shaded_head.png");
//sound
        Mix_Music* bgmusic = Mix_LoadMUS("sound/HeadEmpty.mp3");
        Mix_Chunk* chunks[Chunks];
        chunks[Start] = Mix_LoadWAV("sound/click.wav");
        chunks[Eat] = Mix_LoadWAV("sound/crunch.wav");
        chunks[Death] = Mix_LoadWAV("sound/death.wav");
//text
        Text* texts[Texts];
        texts[Play] = new Text("start",80);
        texts[Exit] = new Text("exit",80);
        texts[GameOver] = new Text("game over press r to replay",65,"font/8-bit Arcade Out.ttf");
        texts[GameOver2] = new Text("game over press r to replay",65,"font/8-bit Arcade In.ttf");
        texts[Point] = new Text(30,"font/dogicabold.ttf");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    State state = START;
    SDL_Event event;
    bool quit = false;
    t1 = SDL_GetTicks();
    delta = 0;
#if 1
    Mix_PlayMusic(bgmusic,-1);
    while(!quit){
        t0 = t1;
        t1 = SDL_GetTicks();
        delta = t1 - t0;
        if(delta < 1000.0f / FPS ){
            SDL_Delay(1000.0f / FPS - delta);
        }
        SDL_RenderPresent(renderer);

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
	#endif
    Shutdown();

	return 0;
}
