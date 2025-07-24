//FormAI DATASET v1.0 Category: Image compression ; Style: lively
#include <stdio.h>
#include <stdlib.h>

/* A fun and unique way to compress an image */

int main() {

  printf("Welcome to the Image Compression Program!\n");
  
  // Inputting the image dimensions (assuming square image)
  int n;
  printf("Please enter the dimension of the square image: ");
  scanf("%d", &n);

  // Taking random pixel values as example
  int image[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      image[i][j] = rand() % 256; // maximum pixel value is 255
    }
  }

  // Printing the original image
  printf("Original Image: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n"); // newline after each row
  }

  // Compressing the image by taking the average of each 2x2 block
  int compressed_image[n/2][n/2];
  for (int i = 0; i < n; i+=2) {
    for (int j = 0; j < n; j+=2) {
      int sum = image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1];
      compressed_image[i/2][j/2] = sum / 4; // average of the 4 pixels
    }
  }

  // Printing the compressed image
  printf("Compressed Image: \n");
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < n/2; j++) {
      printf("%d ", compressed_image[i][j]);
    }
    printf("\n"); // newline after each row
  }

  return 0;
}