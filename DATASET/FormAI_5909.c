//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void draw_pixel(char grid[WIDTH][HEIGHT], int x, int y, char color) {
  grid[x][y] = color;
}

void print_grid(char grid[WIDTH][HEIGHT]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c ", grid[x][y]);
    }
    printf("\n");
  }
}

int main() {
  char grid[WIDTH][HEIGHT];

  // Initialize grid to all white pixels
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      grid[x][y] = '.';
    }
  }

  // Randomly generate pixels
  srand(time(NULL));
  for (int i = 0; i < WIDTH * HEIGHT / 4; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    char color = (rand() % 2 == 0) ? 'X' : 'O';
    draw_pixel(grid, x, y, color);
  }

  // Print the final grid
  print_grid(grid);
  
  return 0;
}