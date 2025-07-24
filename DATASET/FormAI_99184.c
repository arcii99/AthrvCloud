//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

// Constants
#define WIDTH 800
#define HEIGHT 800
#define FPS 60
#define G 6.67408e-11

// Structs
typedef struct {
    double x, y;
} vector_t;

typedef struct {
    vector_t pos, vel;
    double mass, radius;
    Uint32 color;
} celestial_body_t;

// Function prototypes
void init_sdl();
void draw(celestial_body_t *bodies);
void update(celestial_body_t *bodies, double dt);
vector_t calculate_gravity(celestial_body_t a, celestial_body_t b);

// Global variables
SDL_Window *window;
SDL_Renderer *renderer;
bool running = true;

// Main function
int main(int argc, char **argv) {
    srand(time(NULL));

    // Initialize SDL
    init_sdl();

    // Create celestial bodies
    celestial_body_t sun = { .pos = { WIDTH/2, HEIGHT/2 }, .vel = { 0, 0 }, .mass = 1.989e30, .radius = 695700, .color = 0xFFEB3B };
    celestial_body_t earth = { .pos = { WIDTH/2 + 147.09e9, HEIGHT/2 }, .vel = { 0, 29.29e3 }, .mass = 5.972e24, .radius = 6371, .color = 0x2196F3 };
    celestial_body_t moon = { .pos = { WIDTH/2 + 147.09e9 + 384.4e6, HEIGHT/2 }, .vel = { 0, 29.29e3 + 1.02e3 }, .mass = 7.342e22, .radius = 1737.1, .color = 0x9E9E9E };

    // Add bodies to list
    celestial_body_t bodies[] = { sun, earth, moon };
    int n_bodies = sizeof(bodies) / sizeof(*bodies);

    // Simulation loop
    long long int t = 0;
    while (running) {
        // Calculate dt
        double dt = 1.0 / FPS;

        // Handle SDL events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        // Update and draw bodies
        update(bodies, dt);
        draw(bodies);

        // Sleep to maintain FPS
        long long int dt_ms = (int)(dt * 1000);
        long long int elapsed_ms = SDL_GetTicks() - t;
        if (dt_ms > elapsed_ms) {
            usleep(1000 * (dt_ms - elapsed_ms));
        }
        t = SDL_GetTicks();
    }

    // Destroy SDL window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// Initialize SDL
void init_sdl() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Solar System Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// Draw function
void draw(celestial_body_t *bodies) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw bodies
    for (int i = 0; i < sizeof(bodies) / sizeof(*bodies); i++) {
        SDL_SetRenderDrawColor(renderer, (bodies[i].color & 0xFF0000) >> 16, (bodies[i].color & 0x00FF00) >> 8, bodies[i].color & 0x0000FF, SDL_ALPHA_OPAQUE);
        SDL_Rect rect = { (int)(bodies[i].pos.x - bodies[i].radius), (int)(bodies[i].pos.y - bodies[i].radius), (int)(2 * bodies[i].radius), (int)(2 * bodies[i].radius) };
        SDL_RenderFillRect(renderer, &rect);
    }

    // Present renderer
    SDL_RenderPresent(renderer);
}

// Update function
void update(celestial_body_t *bodies, double dt) {
    // Calculate gravity and update velocity/position
    for (int i = 0; i < sizeof(bodies) / sizeof(*bodies); i++) {
        vector_t net_force = { 0, 0 };
        for (int j = 0; j < sizeof(bodies) / sizeof(*bodies); j++) {
            if (i != j) {
                vector_t force = calculate_gravity(bodies[i], bodies[j]);
                net_force.x += force.x;
                net_force.y += force.y;
            }
        }
        vector_t accel = { net_force.x / bodies[i].mass, net_force.y / bodies[i].mass };
        bodies[i].vel.x += dt * accel.x;
        bodies[i].vel.y += dt * accel.y;
        bodies[i].pos.x += dt * bodies[i].vel.x;
        bodies[i].pos.y += dt * bodies[i].vel.y;
    }
}

// Calculate gravitational force between two bodies
vector_t calculate_gravity(celestial_body_t a, celestial_body_t b) {
    vector_t r = { b.pos.x - a.pos.x, b.pos.y - a.pos.y };
    double dist = sqrt(r.x * r.x + r.y * r.y);
    double force = G * a.mass * b.mass / (dist * dist);
    vector_t direction = { r.x / dist, r.y / dist };
    vector_t gravity = { force * direction.x, force * direction.y };
    return gravity;
}