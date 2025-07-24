//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include "SDL2/SDL.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PIXEL_SIZE 10

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int quit = 0;

    // Initialize SDL video subsystem
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    window = SDL_CreateWindow("Pixel Art Generator",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, 0);

    // Set the drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the screen with black color
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Event loop
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    // Draw a pixel on the screen
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderDrawPoint(renderer, event.button.x / PIXEL_SIZE * PIXEL_SIZE,
                                        event.button.y / PIXEL_SIZE * PIXEL_SIZE);
                    SDL_RenderPresent(renderer);
                    break;
            }
        }
    }

    // Cleanup resources and exit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}