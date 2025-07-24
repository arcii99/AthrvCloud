//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: immersive
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Space Invaders Clone",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);

    if(window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);

    // Game loop here

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}