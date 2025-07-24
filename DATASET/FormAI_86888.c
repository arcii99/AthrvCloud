//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_COLOR 8

int image[HEIGHT][WIDTH];

void generatePixelArt(int x, int y, int color) {
  if(x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
    return;
  }
  
  if(image[y][x] != 0) {
    return;
  }
  
  image[y][x] = color;
  
  int newX = x + rand() % 3 - 1;
  int newY = y + rand() % 3 - 1;
  
  generatePixelArt(newX, newY, color);
}

void printImage() {
  for(int y = 0; y < HEIGHT; y++) {
    for(int x = 0; x < WIDTH; x++) {
      if(image[y][x] == 0) {
        printf(" ");
      } else {
        printf("%d", image[y][x]);
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  
  for(int y = 0; y < HEIGHT; y++) {
    for(int x = 0; x < WIDTH; x++) {
      image[y][x] = 0;
    }
  }
  
  for(int color = 1; color <= MAX_COLOR; color++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    
    generatePixelArt(x, y, color);
  }
  
  printImage();
  
  return 0;  
}