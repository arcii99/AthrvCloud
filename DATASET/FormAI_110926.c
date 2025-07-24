//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void generate_pixel_art(int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      int color = rand() % 2;
      printf("%d ", color);
    }
    printf("\n");
  }
}

int main() {
  int size;
  printf("Enter the size of the pixel art: ");
  scanf("%d", &size);

  generate_pixel_art(size);

  return 0;
}