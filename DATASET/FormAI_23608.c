//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640
#define TILE_SIZE 32
#define NUM_OF_TILES_X 20
#define NUM_OF_TILES_Y 20
#define NUM_OF_PELLETS 199

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int type;
    bool eaten;
} Pellet;

SDL_Window* window;
SDL_Renderer* renderer;

Position pacman;
Position ghost;
Pellet* pellets[NUM_OF_PELLETS];

void initialize() {
    pacman.x = 0;
    pacman.y = NUM_OF_TILES_Y / 2 * TILE_SIZE;
    ghost.x = (NUM_OF_TILES_X - 1) * TILE_SIZE;
    ghost.y = pacman.y;
    int pelletIndex = 0;
    for (int i = 0; i < NUM_OF_TILES_X; i++) {
        for (int j = 0; j < NUM_OF_TILES_Y; j++) {
            if (i == 0 || i == NUM_OF_TILES_X - 1 || j == 0 || j == NUM_OF_TILES_Y - 1) {
                pellets[pelletIndex] = malloc(sizeof(Pellet));
                pellets[pelletIndex]->position.x = i * TILE_SIZE;
                pellets[pelletIndex]->position.y = j * TILE_SIZE;
                pellets[pelletIndex]->type = 0;
                pellets[pelletIndex]->eaten = false;
                pelletIndex++;
            } else if (i % 2 == 0 && j % 2 == 0) {
                pellets[pelletIndex] = malloc(sizeof(Pellet));
                pellets[pelletIndex]->position.x = i * TILE_SIZE;
                pellets[pelletIndex]->position.y = j * TILE_SIZE;
                pellets[pelletIndex]->type = 1;
                pellets[pelletIndex]->eaten = false;
                pelletIndex++;
            }
        }
    }
}

void draw() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw pellets
    for (int i = 0; i < NUM_OF_PELLETS; i++) {
        if (!pellets[i]->eaten) {
            if (pellets[i]->type == 0) {
                SDL_Rect wallRect = {pellets[i]->position.x, pellets[i]->position.y, TILE_SIZE, TILE_SIZE};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &wallRect);
            } else {
                SDL_Rect pelletRect = {pellets[i]->position.x + TILE_SIZE / 2 - 2, pellets[i]->position.y + TILE_SIZE / 2 - 2, 4, 4};
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &pelletRect);
            }
        }
    }

    // Draw pacman
    SDL_Rect pacmanRect = {pacman.x + 2, pacman.y + 2, TILE_SIZE - 4, TILE_SIZE - 4};
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &pacmanRect);

    // Draw ghost
    SDL_Rect ghostRect = {ghost.x + 2, ghost.y + 2, TILE_SIZE - 4, TILE_SIZE - 4};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &ghostRect);

    // Update screen
    SDL_RenderPresent(renderer);
}

void handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
    }
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_LEFT]) {
        pacman.x -= 2;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        pacman.x += 2;
    }
    if (keystates[SDL_SCANCODE_UP]) {
        pacman.y -= 2;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        pacman.y += 2;
    }
}

void moveGhost() {
    int dir = rand() % 4;
    switch (dir) {
        case 0: // Left
            if (ghost.x > TILE_SIZE) {
                ghost.x -= TILE_SIZE;
            }
            break;
        case 1: // Right
            if (ghost.x < (NUM_OF_TILES_X - 2) * TILE_SIZE) {
                ghost.x += TILE_SIZE;
            }
            break;
        case 2: // Up
            if (ghost.y > TILE_SIZE) {
                ghost.y -= TILE_SIZE;
            }
            break;
        case 3: // Down
            if (ghost.y < (NUM_OF_TILES_Y - 2) * TILE_SIZE) {
                ghost.y += TILE_SIZE;
            }
            break;
    }
}

bool detectCollisions() {
    // Pacman-ghost collision
    if (pacman.x == ghost.x && pacman.y == ghost.y) {
        return true;
    }
    // Pacman-pellet collision
    for (int i = 0; i < NUM_OF_PELLETS; i++) {
        if (!pellets[i]->eaten && pellets[i]->type == 1 && pacman.x + TILE_SIZE / 2 == pellets[i]->position.x + TILE_SIZE / 2 && pacman.y + TILE_SIZE / 2 == pellets[i]->position.y + TILE_SIZE / 2) {
            pellets[i]->eaten = true;
            return false;
        }
    }
    // Wall collision
    if (pacman.x < TILE_SIZE || pacman.x > (NUM_OF_TILES_X - 2) * TILE_SIZE || pacman.y < TILE_SIZE || pacman.y > (NUM_OF_TILES_Y - 2) * TILE_SIZE) {
        return true;
    }
    return false;
}

void cleanUp() {
    for (int i = 0; i < NUM_OF_PELLETS; i++) {
        free(pellets[i]);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Pac-Man Clone - C Edition", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);
    initialize();
    int frame = 0;
    while (true) {
        handleEvents();
        if (detectCollisions()) {
            printf("Game over!\n");
            cleanUp();
            return 0;
        }
        if (frame % 10 == 0) {
            moveGhost();
        }
        draw();
        SDL_Delay(16);
        frame++;
    }
    return 0;
}