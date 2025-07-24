//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800
#define SCALE 3
#define MAX_ITERATIONS 100

typedef struct _complex{
    float real;
    float imag;
} Complex;

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
Complex julia_set(Complex c, Complex z);

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Fractal Generation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    SDL_Surface *surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);

    float zoom = 1.0;
    Complex c = {0.285, 0.01};
    Complex z = {0, 0};
    int x, y, i, j;
    Uint32 *pixels = (Uint32*)surface->pixels;

    for(x = 0; x < WIDTH; x++){
        for(y = 0; y < HEIGHT; y++){

            z.real = (x - WIDTH/2.0)*4.0/(zoom*WIDTH);
            z.imag = (y - HEIGHT/2.0)*4.0/(zoom*WIDTH);

            z = julia_set(c, z);

            float brightness = log10f((z.real*z.real) + (z.imag*z.imag))/log10f(2.0);
            brightness = (brightness > 1.0) ? 1.0 : brightness;

            Uint8 red = (Uint8)(255.0*brightness);
            Uint8 green = 0;
            Uint8 blue = 0;
            Uint32 color = SDL_MapRGB(surface->format, red, green, blue);
            set_pixel(surface, x, y, color);

        }
    }

    SDL_LockSurface(surface);
    SDL_UpdateTexture(texture, NULL, surface->pixels, WIDTH*sizeof(Uint32));
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    int running = 1;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
            else if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_w:
                        c.imag += 0.01/zoom;
                        break;
                    case SDLK_s:
                        c.imag -= 0.01/zoom;
                        break;
                    case SDLK_a:
                        c.real -= 0.01/zoom;
                        break;
                    case SDLK_d:
                        c.real += 0.01/zoom;
                        break;
                    case SDLK_UP:
                        zoom /= SCALE;
                        break;
                    case SDLK_DOWN:
                        zoom *= SCALE;
                        break;
                }
            }
        }

        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderClear(renderer);
        SDL_LockSurface(surface);

        for(x = 0; x < WIDTH; x++){
            for(y = 0; y < HEIGHT; y++){

                z.real = (x - WIDTH/2.0)*4.0/(zoom*WIDTH);
                z.imag = (y - HEIGHT/2.0)*4.0/(zoom*WIDTH);

                z = julia_set(c, z);

                float brightness = log10f((z.real*z.real) + (z.imag*z.imag))/log10f(2.0);
                brightness = (brightness > 1.0) ? 1.0 : brightness;

                Uint8 red = (Uint8)(255.0*brightness);
                Uint8 green = 0;
                Uint8 blue = 0;
                Uint32 color = SDL_MapRGB(surface->format, red, green, blue);
                set_pixel(surface, x, y, color);

            }
        }

        SDL_UnlockSurface(surface);
        SDL_UpdateTexture(texture, NULL, surface->pixels, WIDTH*sizeof(Uint32));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel){
    Uint32 *pixels = (Uint32*)surface->pixels;
    pixels[y*surface->w + x] = pixel;
}

Complex julia_set(Complex c, Complex z){
    int n = 0;
    Complex temp;
    while(((z.real*z.real)+(z.imag*z.imag)) < 4.0 && n < MAX_ITERATIONS){
        temp.real = (z.real*z.real) - (z.imag*z.imag) + c.real;
        temp.imag = (2.0*z.real*z.imag) + c.imag;
        z = temp;
        n++;
    }

    return z;
}