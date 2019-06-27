//
// Created by mggk on 27/06/19.
//

#ifndef CLASSICO_DEMO_STARFIELD_H
#define CLASSICO_DEMO_STARFIELD_H


#include <SDL2/SDL_system.h>

class starfield {
public:
    void load();
    void render(SDL_Renderer *renderer, int tick);
    void unload();

private:
    const static int starNum = 500;
    struct {
        int x;
        int y;
        int speed;
    } star[starNum];
};


#endif //CLASSICO_DEMO_STARFIELD_H
