//
// Created by mggk on 17/06/19.
//

#include "gfxUtils.h"


void gfxUtils::renderString(SDL_Renderer *renderer, int x, int y, std::string *text, TTF_Font *font, bool center) {
    SDL_Texture *texture = NULL;
    SDL_Rect rect;
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};
    surface = TTF_RenderText_Blended(font, text->c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    if(center == true){
        rect.x = (1280/2)-(text_width/2);
    }else{
        rect.x = x;
    }
    rect.y = y;
    rect.w = text_width;
    rect.h = text_height;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}