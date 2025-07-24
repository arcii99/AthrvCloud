//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct complex {
    float real;
    float imag;
} Complex;

Uint32 pixel_color(SDL_Surface* surface, int x, int y) {
    Uint32* pixels = (Uint32*) surface->pixels;
    return pixels[y * surface->w + x];
}

void set_pixel_color(SDL_Surface* surface, int x, int y, Uint32 color) {
    Uint32* pixels = (Uint32*) surface->pixels;
    pixels[y * surface->w + x] = color;
}

void render(SDL_Surface* surface, Complex c, int max_iterations) {
    float x_min = -2.0;
    float x_max = 2.0;
    float y_min = -2.0;
    float y_max = 2.0;
    float x_range = x_max - x_min;
    float y_range = y_max - y_min;

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            float zx = ((float) x / SCREEN_WIDTH) * x_range + x_min;
            float zy = ((float) y / SCREEN_HEIGHT) * y_range + y_min;

            Complex z;
            z.real = zx;
            z.imag = zy;

            int iterations = 0;
            bool escaped = false;

            while (iterations < max_iterations && !escaped) {
                Complex z_squared;
                z_squared.real = (z.real * z.real) - (z.imag * z.imag);
                z_squared.imag = 2.0 * z.real * z.imag;

                z.real = z_squared.real + c.real;
                z.imag = z_squared.imag + c.imag;

                if (sqrt((z.real * z.real) + (z.imag * z.imag)) > 2.0) {
                    escaped = true;
                }

                iterations++;
            }

            if (iterations == max_iterations) {
                set_pixel_color(surface, x, y, 0x000000);
            } else {
                Uint8 r = 0x00;
                Uint8 g = (iterations * 16) & 0xff;
                Uint8 b = (iterations * 16) & 0xff;

                Uint32 color = SDL_MapRGB(surface->format, r, g, b);
                set_pixel_color(surface, x, y, color);
            }
        }
    }
}

void save(SDL_Surface* surface, const char* filename) {
    SDL_SaveBMP(surface, filename);
}

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Mandelbrot",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    Complex c;
    c.real = -0.7463;
    c.imag = 0.1102;

    render(surface, c, 256);
    save(surface, "mandelbrot.bmp");

    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}