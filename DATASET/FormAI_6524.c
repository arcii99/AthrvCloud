//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MAX_PIXEL_VALUE 255

// Define the dimensions of the pixel art
#define IMAGE_WIDTH 10
#define IMAGE_HEIGHT 10

// Define the color palette
#define NUM_COLORS 3
#define COLOR_RED 0
#define COLOR_GREEN 1
#define COLOR_BLUE 2
#define COLOR_PALETTE { \
    {255, 0, 0}, \
    {0, 255, 0}, \
    {0, 0, 255}, \
}

// Define the pixel art data
unsigned char pixel_data[IMAGE_WIDTH][IMAGE_HEIGHT] = {
    {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED},
    {COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN},
    {COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE},
    {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED},
    {COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN},
    {COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE},
    {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED},
    {COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN},
    {COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE},
    {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_RED},
};

int main(int argc, char* argv[]) {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "Pixel Art Generator",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        printf("Error creating window: %s\n", SDL_GetError());
        return 1;
    }

    // Get the renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED
    );
    if (renderer == NULL) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Set the palette colors
    SDL_Color palette[NUM_COLORS];
    palette[COLOR_RED] = (SDL_Color){255, 0, 0, MAX_PIXEL_VALUE};
    palette[COLOR_GREEN] = (SDL_Color){0, 255, 0, MAX_PIXEL_VALUE};
    palette[COLOR_BLUE] = (SDL_Color){0, 0, 255, MAX_PIXEL_VALUE};

    // Draw the pixel art
    SDL_Rect rect = {0, 0, WINDOW_WIDTH / IMAGE_WIDTH, WINDOW_HEIGHT / IMAGE_HEIGHT};
    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            SDL_SetRenderDrawColor(
                renderer,
                palette[pixel_data[i][j]].r,
                palette[pixel_data[i][j]].g,
                palette[pixel_data[i][j]].b,
                MAX_PIXEL_VALUE
            );
            rect.x = i * rect.w;
            rect.y = j * rect.h;
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    // Render the scene
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    SDL_bool quit = SDL_FALSE;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}