//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_COLOR 7

int main(void) {
  int canvas[HEIGHT][WIDTH];
  
  srand(time(NULL));
  
  // Initialize canvas with random colors
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      canvas[i][j] = rand() % MAX_COLOR;
    }
  }
  
  // Print canvas as pixel art
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      switch (canvas[i][j]) {
        case 0:
          printf("⬜️ ");
          break;
        case 1:
          printf("🟥 ");
          break;
        case 2:
          printf("🟦 ");
          break;
        case 3:
          printf("🟩 ");
          break;
        case 4:
          printf("🟨 ");
          break;
        case 5:
          printf("🟪 ");
          break;
        case 6:
          printf("🟧 ");
          break;
        default:
          break;
      }
    }
    printf("\n");
  }
  
  return 0;
}