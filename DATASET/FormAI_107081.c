//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <SDL2/SDL.h>
#include <stdio.h>

// Define the size of the pixel art.
#define WIDTH 320
#define HEIGHT 240
#define PIXEL_SIZE 2

// Declare the pixel art buffer.
unsigned char pixels[WIDTH * HEIGHT];

// Declare function to draw the pixel art.
void drawPixels(SDL_Renderer *renderer, unsigned char *pixels, int pixelSize) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate position of current pixel.
            int index = (y * WIDTH) + x;

            // Set the color of the pixel based on its value.
            SDL_SetRenderDrawColor(renderer, pixels[index], pixels[index], pixels[index], 255);

            // Draw the pixel on the screen.
            SDL_Rect rect = { x * pixelSize, y * pixelSize, pixelSize, pixelSize };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

int main(int argc, char *argv[]) {
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer.
    SDL_Window *window = SDL_CreateWindow("Pixel Art Generator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH * PIXEL_SIZE, HEIGHT * PIXEL_SIZE, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Clear the pixel art buffer to all white.
    memset(pixels, 255, WIDTH * HEIGHT);

    // Draw a single pixel.
    pixels[200] = 0;
    pixels[201] = 255;
    pixels[202] = 0;

    // Draw the pixel art to the screen.
    drawPixels(renderer, pixels, PIXEL_SIZE);
    SDL_RenderPresent(renderer);

    // Main event loop.
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                // Exit the program when the window is closed.
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
        }
    }

    return 0;
}