//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 10
#define IMAGE_WIDTH 50
#define IMAGE_HEIGHT 50

char pixels[IMAGE_HEIGHT][IMAGE_WIDTH];

char generatePixel() {
  int randNum = rand() % 100;
  if (randNum < 25) {
    return ' ';
  } else if (randNum < 40) {
    return '.';
  } else if (randNum < 70) {
    return ':';
  } else if (randNum < 85) {
    return 'o';
  } else if (randNum < 95) {
    return 'O';
  } else {
    return '@';
  }
}

void generateImage() {
  srand(time(NULL));
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      pixels[i][j] = generatePixel();
    }
  }
}

void printImage() {
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      printf("%c ", pixels[i][j]);
    }
    printf("\n");
  }
}

int main() {
  generateImage();
  printImage();
  return 0;
}