//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for image dimensions
#define IMAGE_HEIGHT 512
#define IMAGE_WIDTH 512

// Define constants for image channels
#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2

// Define function to swap two values
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Define function to convert RGB color to grayscale
void convertToGrayscale(unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][3]) {
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      // Calculate grayscale value using weighted formula
      unsigned char grayscale = 0.299 * image[i][j][RED_CHANNEL] + 0.587 * image[i][j][GREEN_CHANNEL] + 0.114 * image[i][j][BLUE_CHANNEL];
      // Set all channels to grayscale value
      image[i][j][RED_CHANNEL] = grayscale;
      image[i][j][GREEN_CHANNEL] = grayscale;
      image[i][j][BLUE_CHANNEL] = grayscale;
    }
  }
}

// Define function to apply a blur filter to an image
void applyBlurFilter(unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][3]) {
  unsigned char result[IMAGE_HEIGHT][IMAGE_WIDTH][3];
  // Initialize all values to 0
  memset(result, 0, sizeof(result));
  // Apply filter to each pixel
  for (int i = 1; i < IMAGE_HEIGHT-1; i++) {
    for (int j = 1; j < IMAGE_WIDTH-1; j++) {
      for (int channel = 0; channel < 3; channel++) {
        // Calculate weighted average of surrounding pixels
        int average = image[i-1][j-1][channel] + image[i-1][j][channel] + image[i-1][j+1][channel] +
                      image[i][j-1][channel]   + image[i][j][channel]   + image[i][j+1][channel]   +
                      image[i+1][j-1][channel] + image[i+1][j][channel] + image[i+1][j+1][channel];
        average /= 9;
        // Set result pixel to the calculated value
        result[i][j][channel] = average;
      }
    }
  }
  // Copy result back into original image
  memcpy(image, result, sizeof(image));
}

int main() {
  // Initialize image with random RGB values
  unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][3];
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      image[i][j][RED_CHANNEL] = rand() % 256;
      image[i][j][GREEN_CHANNEL] = rand() % 256;
      image[i][j][BLUE_CHANNEL] = rand() % 256;
    }
  }

  // Apply grayscale filter
  convertToGrayscale(image);

  // Apply blur filter
  applyBlurFilter(image);

  // Print first 10 pixels of image as RGB values
  printf("First 10 pixels of image:\n");
  for (int i = 0; i < 10; i++) {
    printf("(%d, %d, %d)\n", image[i][0][RED_CHANNEL], image[i][0][GREEN_CHANNEL], image[i][0][BLUE_CHANNEL]);
  }

  // Swap two rows of the image
  int row1 = 100;
  int row2 = 200;
  for (int j = 0; j < IMAGE_WIDTH; j++) {
    swap(&image[row1][j][RED_CHANNEL], &image[row2][j][RED_CHANNEL]);
    swap(&image[row1][j][GREEN_CHANNEL], &image[row2][j][GREEN_CHANNEL]);
    swap(&image[row1][j][BLUE_CHANNEL], &image[row2][j][BLUE_CHANNEL]);
  }

  // Print first 10 pixels of modified image as RGB values
  printf("First 10 pixels of modified image:\n");
  for (int i = 0; i < 10; i++) {
    printf("(%d, %d, %d)\n", image[i][0][RED_CHANNEL], image[i][0][GREEN_CHANNEL], image[i][0][BLUE_CHANNEL]);
  }

  return 0;
}