//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

bool init(SDL_Window** window, SDL_Renderer** renderer);
void drawMandelbrot(SDL_Renderer* renderer, double x_start, double x_end, double y_start, double y_end);

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    if(!init(&window, &renderer)) {
        printf("Initialization failed!\n");
        return 1;
    }
    
    drawMandelbrot(renderer, -2.0, 1.0, -1.5, 1.5);
    
    SDL_Event event;
    bool running = true;
    
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

bool init(SDL_Window** window, SDL_Renderer** renderer) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized!\n Error: %s", SDL_GetError());
        return false;
    }
    
    *window = SDL_CreateWindow("Mandelbrot Set Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    if(*window == NULL) {
        printf("Window could not be created!\n Error: %s", SDL_GetError());
        return false;
    }
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    
    if(*renderer == NULL) {
        printf("Renderer could not be created!\n Error: %s", SDL_GetError());
        return false;
    }
    
    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
    SDL_RenderClear(*renderer);
    SDL_RenderPresent(*renderer);
    
    return true;
}

void drawMandelbrot(SDL_Renderer* renderer, double x_start, double x_end, double y_start, double y_end) {
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            double x = x_start + (x_end - x_start) * ((double)i/WIDTH);
            double y = y_start + (y_end - y_start) * ((double)j/HEIGHT);
            
            double cx = x;
            double cy = y;
            
            int iter = 0;
            
            while(iter < MAX_ITER) {
                double x2 = x * x;
                double y2 = y * y;
                
                if(x2 + y2 > 4) {
                    break;
                }
                
                double xt = x2 - y2 + cx;
                double yt = 2 * x * y + cy;
                
                x = xt;
                y = yt;
                
                iter++;
            }
            
            if(iter == MAX_ITER) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            } else {
                double t = (double)iter/MAX_ITER;
                int r = (int)(9 * (1-t) * t * t * t * 255);
                int g = (int)(15 * (1-t) * (1-t) * t * t * 255);
                int b = (int)(8.5 * (1-t) * (1-t) * (1-t) * t * 255);
                
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            }
            
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
    
    SDL_RenderPresent(renderer);
}