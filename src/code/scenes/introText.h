//
// Created by mggk on 16/06/19.
//

#ifndef CLASSICO_DEMO_INTROTEXT_H
#define CLASSICO_DEMO_INTROTEXT_H

#include "string"
#include <SDL2/SDL_ttf.h>

class introText {
public:
    void load();
    void render(SDL_Renderer *renderer);
    void unload();

private:
    TTF_Font *font =  NULL;
    std::string textLine[4];

};


#endif //CLASSICO_DEMO_INTROTEXT_H
