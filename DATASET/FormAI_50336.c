//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

float map(float value, float min_from, float max_from, float min_to, float max_to)
{
    return (value - min_from) * (max_to - min_to) / (max_from - min_from) + min_to;
}

void drawFractal(SDL_Renderer* renderer, float x, float y, float angle, float length, int depth)
{
    if (depth == 0) {
        return;
    }

    float x2 = x + cos(angle) * length;
    float y2 = y + sin(angle) * length;

    SDL_RenderDrawLine(renderer, (int)x, (int)y, (int)x2, (int)y2);

    drawFractal(renderer, x2, y2, angle - M_PI / 4, length / 2, depth - 1);
    drawFractal(renderer, x2, y2, angle + M_PI / 4, length / 2, depth - 1);
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Fractal Generation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    float x = WINDOW_WIDTH / 2;
    float y = WINDOW_HEIGHT - 40;
    float angle = -M_PI / 2;
    float length = 200;

    drawFractal(renderer, x, y, angle, length, 10);

    SDL_RenderPresent(renderer);

    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }
    }
}