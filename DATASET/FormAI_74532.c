//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480

int main() {
  srand(time(NULL));
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Pixel Art Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_RenderClear(renderer);

  int i, j;
  int pixel_size = 5;

  for (i = 0; i < WIDTH; i += pixel_size) {
    for (j = 0; j < HEIGHT; j += pixel_size) {
      SDL_Rect pixel = {i, j, pixel_size, pixel_size};
      int r = rand() % 255;
      int g = rand() % 255;
      int b = rand() % 255;
      SDL_SetRenderDrawColor(renderer, r, g, b, 255);
      SDL_RenderFillRect(renderer, &pixel);
    }
  }

  SDL_RenderPresent(renderer);
  SDL_Delay(3000);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}