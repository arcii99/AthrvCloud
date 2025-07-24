//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *pixels;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window and renderer
    SDL_CreateWindowAndRenderer(256, 256, 0, &window, &renderer);

    // Create a texture to hold the image data
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 256, 256);

    // Lock the texture so we can write to its pixels
    SDL_LockTexture(texture, NULL, (void **)&pixels, NULL);

    // Loop through each pixel and set its color
    for(int y = 0; y < 256; y++) {
        for(int x = 0; x < 256; x++) {
            int index = y * 256 + x;
            pixels[index] = SDL_MapRGBA(SDL_GetWindowSurface(window)->format, x, y, 0, 255);
        }
    }

    // Unlock the texture so it can be rendered
    SDL_UnlockTexture(texture);

    // Clear the screen and render the texture
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for the user to exit the program
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // Clean up and exit
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}