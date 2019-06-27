//
// Created by mggk on 27/06/19.
//

#include "starfield.h"
void starfield::load() {
    //Generating random star position
    for(int i = 0; i< this->starNum; i++){
        this->star[i].x = rand()%(1280 + 1);
        this->star[i].y = rand()%(720 + 1);
        this->star[i].speed = rand()%(5-1 + 1) + 1;
    }
}

void starfield::render(SDL_Renderer *renderer, int tick) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(int i = 0; i< this->starNum; i++){
        if(this->star[i].x < 0){
            this->star[i].x = 1280;
        }else{
            this->star[i].x-=this->star[i].speed;
        }
        SDL_RenderDrawPoint(renderer,this->star[i].x,this->star[i].y);
    }
}

void starfield::unload() {

}