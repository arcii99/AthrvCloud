//FormAI DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Color constants
const int MAX_COLOR = 0xFFFFFF;
const int BLACK = 0x000000;

// Mandelbrot constants
const int MAX_ITERATIONS = 1000;
const double ZOOM_FACTOR = 1.1;

// Struct to represent a complex number
typedef struct {
    double real;
    double imag;
} Complex;

// Calculate the square of a complex number
Complex square(Complex z) {
    Complex z_squared;
    z_squared.real = z.real * z.real - z.imag * z.imag;
    z_squared.imag = 2 * z.real * z.imag;
    return z_squared;
}

// Check if a complex number is in the Mandelbrot Set
bool in_mandelbrot_set(Complex c) {
    Complex z = {0, 0};
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        z = square(z);
        z.real += c.real;
        z.imag += c.imag;
        if (sqrt(z.real * z.real + z.imag * z.imag) > 2) {
            return false;
        }
    }
    return true;
}

// Draw the Mandelbrot Set
void draw_mandelbrot(SDL_Renderer *renderer, double zoom) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            Complex c = {
                (2.0 * x - SCREEN_WIDTH) / (2.0 * zoom * SCREEN_WIDTH / SCREEN_HEIGHT),
                (SCREEN_HEIGHT - 2.0 * y) / (2.0 * zoom * SCREEN_HEIGHT / SCREEN_WIDTH)
            };
            int color = in_mandelbrot_set(c) ? BLACK : MAX_COLOR;
            SDL_SetRenderDrawColor(renderer, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, 0xFF);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    double zoom = 1.0;
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        draw_mandelbrot(renderer, zoom);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        zoom /= ZOOM_FACTOR;
                    } else if (event.button.button == SDL_BUTTON_RIGHT) {
                        zoom *= ZOOM_FACTOR;
                    }
                    break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}