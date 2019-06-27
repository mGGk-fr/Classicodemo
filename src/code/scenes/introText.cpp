//
// Created by mggk on 16/06/19.
//

#include "introText.h"
#include "../gfxUtils.h"

void introText::load() {
    font = TTF_OpenFont("./fonts/dafont.ttf",28);
    textLine[0] = "mGGk speaking here, welcome to another new shitty release for the demoscene family";
    textLine[1] = "This presentation is running on the Playstation Classic itself, it's not a Playstation 1 demo";
    textLine[2] = "This was made possible thanks to the huge work made by the AutoBleem Team which i'm part of";
    textLine[3] = "Greetz to elites, fucking to lamers :D";
}

void introText::render(SDL_Renderer *renderer) {
    for(int i = 0; i<4;i++){
        gfxUtils::renderString(renderer, 0,250+(30*i),&textLine[i],font,true);
    }
}

void introText::unload() {
    TTF_CloseFont(this->font);

}