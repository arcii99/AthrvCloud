//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define PIXEL_SIZE 10
#define ARRAY_SIZE (SCREEN_WIDTH / PIXEL_SIZE) * (SCREEN_HEIGHT / PIXEL_SIZE)

double pixels[ARRAY_SIZE];

void generate_pixels() {
    int i;
    double mean = 0.5;
    double variance = 0.1;
    double standard_deviation = sqrt(variance);

    srand(time(0));

    for (i = 0; i < ARRAY_SIZE; i++) {
        pixels[i] = (double)rand() / RAND_MAX;

        while (pixels[i] < 0 || pixels[i] > 1) {
            pixels[i] = (double)rand() / RAND_MAX;
        }

        pixels[i] = standard_deviation * sqrt(-2 * log(pixels[i])) + mean;
    }

}

void draw_pixels(SDL_Renderer* renderer) {
    int i, j;
    double pixel;
    SDL_Rect pixel_rect;

    for (i = 0; i < SCREEN_HEIGHT / PIXEL_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / PIXEL_SIZE; j++) {
            pixel = pixels[i * (SCREEN_WIDTH / PIXEL_SIZE) + j];

            if (pixel < 0.2) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else if (pixel < 0.4) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            }
            else if (pixel < 0.6) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            }
            else if (pixel < 0.8) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            }

            pixel_rect.x = j * PIXEL_SIZE;
            pixel_rect.y = i * PIXEL_SIZE;
            pixel_rect.w = PIXEL_SIZE;
            pixel_rect.h = PIXEL_SIZE;

            SDL_RenderFillRect(renderer, &pixel_rect);
        }
    }
}

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int running = 1;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Pixel Art Generator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    generate_pixels();

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        draw_pixels(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}