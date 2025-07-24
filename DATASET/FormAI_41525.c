//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

#define WIDTH 700
#define HEIGHT 700

void init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Fractal Generation",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH,
                              HEIGHT,
                              SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void drawLine(int xi, int yi, int xf, int yf) {
    SDL_RenderDrawLine(renderer, xi, yi, xf, yf);
    SDL_RenderPresent(renderer);
}

void drawFractal(int xi, int yi, int angle, int depth) {
    if (depth == 0) {
        return;
    }

    int xf = xi + cos(angle * M_PI / 180.0) * depth * 10;
    int yf = yi + sin(angle * M_PI / 180.0) * depth * 10;

    drawLine(xi, yi, xf, yf);

    drawFractal(xf, yf, angle - 45, depth - 1);
    drawFractal(xf, yf, angle + 45, depth - 1);
}

int main() {
    init();

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        int xi = WIDTH / 2;
        int yi = HEIGHT / 2;
        int angle = -90;

        drawFractal(xi, yi, angle, 8);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}