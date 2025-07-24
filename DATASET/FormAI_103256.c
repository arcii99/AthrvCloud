//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 256

typedef struct {
  int x;
  int y;
} Point;

void set_watermark(char image[IMAGE_SIZE][IMAGE_SIZE], char watermark[IMAGE_SIZE][IMAGE_SIZE]) {
  for (int x = 0; x < IMAGE_SIZE; x++) {
    for (int y = 0; y < IMAGE_SIZE; y++) {
      if (watermark[x][y] == 1) {
        image[x][y] = image[x][y] % 2 == 0 ? image[x][y] + 1 : image[x][y];
      }
    }
  }
}

Point find_watermark(char image[IMAGE_SIZE][IMAGE_SIZE]) {
  Point watermark_loc;
  int counter = 0;
  for (int x = 0; x < IMAGE_SIZE; x++) {
    for (int y = 0; y < IMAGE_SIZE; y++) {
      if (image[x][y] % 2 == 1) {
        counter++;
      }
      if (counter > 50) {
        watermark_loc.x = x;
        watermark_loc.y = y;
        return watermark_loc;
      }
    }
  }
  return watermark_loc;
}

int main() {
  char image[IMAGE_SIZE][IMAGE_SIZE];
  char watermark[IMAGE_SIZE][IMAGE_SIZE];

  // Initialize the image and watermark
  for (int x = 0; x < IMAGE_SIZE; x++) {
    for (int y = 0; y < IMAGE_SIZE; y++) {
      image[x][y] = rand() % 255;
      watermark[x][y] = rand() % 2;
    }
  }

  // Set the watermark
  set_watermark(image, watermark);

  // Find the watermark
  Point watermark_loc = find_watermark(image);

  // Print out the watermark location
  printf("Watermark at (%d, %d)", watermark_loc.x, watermark_loc.y);

  return 0;
}