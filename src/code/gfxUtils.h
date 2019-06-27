//
// Created by mggk on 17/06/19.
//

#ifndef CLASSICO_DEMO_GFXUTILS_H
#define CLASSICO_DEMO_GFXUTILS_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class gfxUtils {
public:
    static void renderString(SDL_Renderer *renderer, int x, int y, std::string *text, TTF_Font *font, bool center = false);
};


#endif //CLASSICO_DEMO_GFXUTILS_H
