//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 10

int cells[WINDOW_HEIGHT/CELL_SIZE][WINDOW_WIDTH/CELL_SIZE] = {0};
int neighbor_counts[WINDOW_HEIGHT/CELL_SIZE][WINDOW_WIDTH/CELL_SIZE] = {0};

void init_cells()
{
    srand(time(NULL));
    for (int y = 0; y < WINDOW_HEIGHT/CELL_SIZE; y++) {
        for (int x = 0; x < WINDOW_WIDTH/CELL_SIZE; x++) {
            cells[y][x] = rand() % 2;
        }
    }
}

void count_neighbors()
{
    for (int y = 0; y < WINDOW_HEIGHT/CELL_SIZE; y++) {
        for (int x = 0; x < WINDOW_WIDTH/CELL_SIZE; x++) {
            int count = 0;
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    if (!(i == 0 && j == 0) && y+j >= 0 && y+j < WINDOW_HEIGHT/CELL_SIZE && x+i >= 0 && x+i < WINDOW_WIDTH/CELL_SIZE) {
                        count+= cells[y+j][x+i];
                    }
                }
            }
            neighbor_counts[y][x] = count;
        }
    }
}

void update_cells()
{
    count_neighbors();
    for (int y = 0; y < WINDOW_HEIGHT/CELL_SIZE; y++) {
        for (int x = 0; x < WINDOW_WIDTH/CELL_SIZE; x++) {
            if (cells[y][x] == 0 && neighbor_counts[y][x] == 3) {
                cells[y][x] = 1;
            } else if (cells[y][x] == 1 && (neighbor_counts[y][x] < 2 || neighbor_counts[y][x] > 3)) {
                cells[y][x] = 0;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    init_cells();

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        update_cells();

        for (int y = 0; y < WINDOW_HEIGHT/CELL_SIZE; y++) {
            for (int x = 0; x < WINDOW_WIDTH/CELL_SIZE; x++) {
                if (cells[y][x] == 1) {
                    SDL_Rect rect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}