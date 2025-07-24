//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>

int main() {
  int width, height, block_size;
  printf("Enter the width of the image: ");
  scanf("%d", &width);
  printf("Enter the height of the image: ");
  scanf("%d", &height);
  printf("Enter the size of each pixel block: ");
  scanf("%d", &block_size);

  // Clear the console
  system("cls");

  for (int i = 0; i < height; i += block_size) {
    for (int j = 0; j < width; j += block_size) {
      // Generate a random color for the current pixel block
      int red = rand() % 256;
      int green = rand() % 256;
      int blue = rand() % 256;

      // Print out the pixel block with the generated color
      for (int k = i; k < i + block_size; k++) {
        for (int l = j; l < j + block_size; l++) {
          if (k < height && l < width) {
            printf("\x1b[48;2;%d;%d;%dm ", red, green, blue);
          }
        }
        printf("\n");
      }
    }
  }

  return 0;
}