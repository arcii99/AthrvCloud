//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void mandelbrot() {
    double min_x = -2.0;
    double max_x = 1.0;
    double min_y = -1.5;
    double max_y = 1.5;

    int max_iterations = 100;
    int bailout = 2;

    double x, y, x0, y0, r, i, rn, in;
    int iterations;

    for(int py = 0; py < WINDOW_HEIGHT; py++) {
        for(int px = 0; px < WINDOW_WIDTH; px++) {
            x0 = min_x + (max_x - min_x) * px / WINDOW_WIDTH;
            y0 = min_y + (max_y - min_y) * py / WINDOW_HEIGHT;

            x = 0.0;
            y = 0.0;
            iterations = 0;

            while(x*x + y*y < bailout*bailout && iterations < max_iterations) {
                r = x*x - y*y + x0;
                i = 2.0 * x * y + y0;
                x = r;
                y = i;
                iterations++;
            }

            if(iterations >= max_iterations) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            } else {
                in = py + iterations - log2(log2(sqrt(x*x + y*y))) / log2(2);
                rn = px + iterations - log2(log2(sqrt(x*x + y*y))) / log2(2);
                SDL_SetRenderDrawColor(renderer, 255 * rn / WINDOW_WIDTH, 255 * in / WINDOW_HEIGHT, 255 * (iterations + 1 - log2(log2(sqrt(x*x + y*y)))) / max_iterations, 255);
            }
            
            SDL_RenderDrawPoint(renderer, px, py);
        }
    }

    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Mandelbrot Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    mandelbrot();

    SDL_Event event;
    int running = 1;

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    return 0;
}