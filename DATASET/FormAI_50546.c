//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define FPS 60

#define G 6.67430E-11

typedef struct Body {
    double x, y;
    double vx, vy;
    double mass;
    int r, g, b;
} Body;

Body* create_body(double x, double y, double vx, double vy, double mass, int r, int g, int b) {
    Body* body = (Body*)malloc(sizeof(Body));
    body->x = x;
    body->y = y;
    body->vx = vx;
    body->vy = vy;
    body->mass = mass;
    body->r = r;
    body->g = g;
    body->b = b;
    return body;
}

void calculate_forces(Body* bodies[], int n) {
    for (int i = 0; i < n; i++) {
        Body* body1 = bodies[i];
        double fx = 0;
        double fy = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Body* body2 = bodies[j];
                double dx = body2->x - body1->x;
                double dy = body2->y - body1->y;
                double d = sqrt(dx * dx + dy * dy);
                double f = G * body1->mass * body2->mass / (d * d);
                fx += f * dx / d;
                fy += f * dy / d;
            }
        }
        body1->vx += fx / body1->mass;
        body1->vy += fy / body1->mass;
    }
}

void update_bodies(Body* bodies[], int n, double dt) {
    for (int i = 0; i < n; i++) {
        Body* body = bodies[i];
        body->x += body->vx * dt;
        body->y += body->vy * dt;
    }
}

void draw_bodies(SDL_Renderer* renderer, Body* bodies[], int n) {
    for (int i = 0; i < n; i++) {
        Body* body = bodies[i];
        SDL_SetRenderDrawColor(renderer, body->r, body->g, body->b, 255);
        SDL_RenderDrawPoint(renderer, body->x, body->y);
    }
}

int main(int argc, char** argv) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create a window
    SDL_Window* window = SDL_CreateWindow("Solar System Simulation", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    
    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the bodies
    Body* sun = create_body(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 1.989E+30, 255, 255, 0);
    Body* earth = create_body(SCREEN_WIDTH / 2 + 1.496E+11, SCREEN_HEIGHT / 2, 0, -29780, 5.972E+24, 0, 0, 255);
    Body* moon = create_body(SCREEN_WIDTH / 2 + 1.496E+11 + 3.844E+8, SCREEN_HEIGHT / 2, 0, -29780 + 1022, 7.342E+22, 200, 200, 200);
    Body* bodies[] = {sun, earth, moon};
    int n = 3;
    
    // Main loop
    double dt = 86400 / FPS; // 86400 seconds in a day
    Uint32 start_time = 0;
    Uint32 frame_time = 1000 / FPS;
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        start_time = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        calculate_forces(bodies, n);
        update_bodies(bodies, n, dt);
        draw_bodies(renderer, bodies, n);
        SDL_RenderPresent(renderer);
        Uint32 end_time = SDL_GetTicks();
        Uint32 elapsed_time = end_time - start_time;
        if (elapsed_time < frame_time) {
            SDL_Delay(frame_time - elapsed_time);
        }
    }
    
    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}