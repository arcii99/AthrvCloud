//FormAI DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800
#define ESCAPE_RADIUS 2

int main() {
    // SDL Initialization
    SDL_Window *window = SDL_CreateWindow("Fractal Generator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Allocating pixel array
    uint32_t *pixels = malloc(WIDTH * HEIGHT * sizeof(uint32_t));

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double complex c = ((double)x - WIDTH / 2) / (WIDTH / 4.0) + (((double)y - HEIGHT / 2) / (HEIGHT / 4.0)) * I;
            double complex z = 0;
            int iter = 0;

            while (cabs(z) < ESCAPE_RADIUS && iter < 100) {
                z = cpow(z, 2) + c;
                iter++;
            }

            // Coloring the pixel
            if (iter == 100) {
                pixels[x + y * WIDTH] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, 0, 0, 0);
            } else {
                uint8_t r = (iter * 10) % 256;
                uint8_t g = (iter * 20) % 256;
                uint8_t b = (iter * 30) % 256;
                pixels[x + y * WIDTH] = SDL_MapRGB(SDL_GetWindowSurface(window)->format, r, g, b);
            }
        }
    }

    // Drawing the pixels
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(uint32_t));
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Main event loop
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(pixels);

    return 0;
}