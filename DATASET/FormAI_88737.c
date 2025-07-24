//FormAI DATASET v1.0 Category: Fractal Generation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

#define MAX_ITER 1000

typedef struct {
    double x, y;
} complex;

complex c_add(complex a, complex b) {
    return (complex) {a.x + b.x, a.y + b.y};
}

complex c_mul(complex a, complex b) {
    return (complex) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}

double c_mod2(complex a) {
    return a.x * a.x + a.y * a.y;
}

complex c_pow(complex a, int n) {
    complex res = (complex) {1, 0};
    for (int i = 1; i <= n; i++) {
        res = c_mul(res, a);
    }
    return res;
}

Uint32 get_color(int iter) {
    if (iter == MAX_ITER) {
        return 0;
    }
    int r, g, b;
    r = iter % 64 < 32 ? iter % 32 * 4 : 127 - iter % 32 * 4;
    g = iter % 16 < 8 ? iter % 8 * 8 : 127 - iter % 8 * 8;
    b = iter % 128;
    return SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), r, g, b);
}

int mandelbrot_point(complex c) {
    complex z = (complex) {0, 0};
    int iter = 0;
    while (iter < MAX_ITER && c_mod2(z) < 4) {
        z = c_add(c_mul(z, z), c);
        iter++;
    }
    return iter;
}

void generate(SDL_Renderer *renderer) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            complex c = (complex) {4. / WIDTH * x - 2, -4. / HEIGHT * y + 2};
            int iter = mandelbrot_point(c);
            Uint32 color = get_color(iter);
            SDL_SetRenderDrawColor(renderer, color >> 16, (color >> 8) & 0xff, color & 0xff, 0xff);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    generate(renderer);
    SDL_RenderPresent(renderer);
    while (1) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                SDL_Quit();
                return 0;
            }
        }
    }
}