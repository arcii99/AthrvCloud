//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define MAX_COLOR 255

int main(void) {
  srand(time(NULL)); // Seed the random number generator with current time

  char pixels[HEIGHT][WIDTH]; // 2D array to store the pixel values
  memset(pixels, 0, sizeof(pixels)); // Initialize all pixels to 0 (black)

  // Generate random pixels (50% chance of being white)
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int r = rand() % 2; // Randomly choose 0 or 1
      pixels[y][x] = r * MAX_COLOR; // Set pixel to black or white
    }
  }

  // Output the pixels as a C array
  printf("#define WIDTH %d\n", WIDTH);
  printf("#define HEIGHT %d\n", HEIGHT);
  printf("const unsigned char PIXELS[%d][%d] = {\n", HEIGHT, WIDTH);
  for (int y = 0; y < HEIGHT; y++) {
    printf("  {");
    for (int x = 0; x < WIDTH; x++) {
      printf("%d", pixels[y][x]);
      if (x < WIDTH - 1) {
        printf(", ");
      }
    }
    printf("}");
    if (y < HEIGHT - 1) {
      printf(",");
    }
    printf("\n");
  }
  printf("};\n");

  return 0;
}