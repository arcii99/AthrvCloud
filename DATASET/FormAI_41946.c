//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define ASCII_RANGE 256

void convertToASCII(unsigned char img[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  char ascii[ASCII_RANGE] = {' ', '.', ',', ':', ';', 'o', 'x', '#', '@'};
  int range = ASCII_RANGE - 1;
  int step = 256 / range;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      int index = img[j][i] / step;
      printf("%c", ascii[index]);
    }
    printf("\n");
  }
}

int main() {
  unsigned char image[MAX_WIDTH][MAX_HEIGHT];
  FILE *fp = fopen("image.bin", "rb");
  if (!fp) {
    printf("Error opening file");
    return 1;
  }
  fread(image, sizeof(unsigned char), MAX_WIDTH*MAX_HEIGHT, fp);
  fclose(fp);

  convertToASCII(image, MAX_WIDTH, MAX_HEIGHT);

  return 0;
}