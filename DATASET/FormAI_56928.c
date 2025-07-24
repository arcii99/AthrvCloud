//FormAI DATASET v1.0 Category: Image Classification system ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 28

int main() {
  // 2D array to represent image
  int image[IMAGE_SIZE][IMAGE_SIZE];

  // randomly fill in image array with values between 0 and 255
  for (int i = 0; i < IMAGE_SIZE; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      image[i][j] = rand() % 256;
    }
  }

  // print out the original image
  printf("Original Image:\n");
  for (int i = 0; i < IMAGE_SIZE; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      printf("%3d ", image[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // apply image classification algorithm
  int black_pixel_count = 0;
  for (int i = 0; i < IMAGE_SIZE; i++) {
    for (int j = 0; j < IMAGE_SIZE; j++) {
      if (image[i][j] < 128) {
        black_pixel_count++;
      }
    }
  }

  // determine classification of image based on number of black pixels
  if (black_pixel_count < IMAGE_SIZE * IMAGE_SIZE * 0.2) {
    printf("Image classified as mostly white.\n");
  } else if (black_pixel_count > IMAGE_SIZE * IMAGE_SIZE * 0.8) {
    printf("Image classified as mostly black.\n");
  } else {
    printf("Image classified as grayscale.\n");
  }

  return 0;
}