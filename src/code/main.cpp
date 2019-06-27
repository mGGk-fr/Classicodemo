#include <iostream>
#include "main.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include "gfxUtils.h"
#include "scenes/introText.h"
#include "scenes/starfield.h"
using namespace std;


int main(int argc, char *argv[]) {
    int tick = 0;
    string tickStr;
    bool end = false;
    bool debug = true;
    int scene = 2;

    Mix_Init(0);
    TTF_Init();

    introText *sceneIntro = new introText();
    sceneIntro->load();

    starfield *sf = new starfield();
    sf->load();

    TTF_Font *debugFont =  NULL;
    SDL_Texture *message = NULL;
    SDL_Rect Message_rect;
    Mix_Music *gMusic = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_InitSubSystem(SDL_INIT_AUDIO);


    debugFont = TTF_OpenFont("./fonts/dafont.ttf",24);
    if (debugFont == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        exit(EXIT_FAILURE);
    }
    gMusic = Mix_LoadMUS( "./music.wav" );

    Mix_PlayMusic( gMusic, -1 );
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    SDL_Window *window = SDL_CreateWindow("ClassicoDemo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720,0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    while(!end){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        switch(scene){
            case 1:
                sceneIntro->render(renderer);
                break;
            case 2:
                sf->render(renderer);
                break;

        }
        if(debug){
            tickStr = std::to_string(tick);
            gfxUtils::renderString(renderer, 0, 0, &tickStr, debugFont);

        }
        if(tick > 1000){
            //sceneIntro->unload();
            //end = true;
        }

        SDL_RenderPresent(renderer);
        tick++;
    }
    exit(0);

}


