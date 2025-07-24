//FormAI DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>

int main() {
  // Initializing variables
  int input_image[28][28];
  int kernel[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
  int output_image[28][28] = {0};

  // Filling input_image with random values (0-255)
  for(int i=0; i<28; i++) {
    for(int j=0; j<28; j++) {
      input_image[i][j] = rand()%256;
    }
  }

  // Applying kernel to input_image to generate output_image
  for (int i = 1; i < 27; i++) {
    for (int j = 1; j < 27; j++) {
      int sum = 0;
      for (int k = -1; k < 2; k++) {
        for (int l = -1; l < 2; l++) {
          sum += input_image[i+k][j+l] * kernel[k+1][l+1];
        }
      }
      output_image[i][j] = sum>255? 255:sum<0? 0:sum;
    }
  }

  // Displaying the input_image and output_image
  printf("Input Image:\n");
  for(int i=0; i<28; i++) {
    for(int j=0; j<28; j++) {
      printf("%3d ", input_image[i][j]);
    }
    printf("\n");
  }
  printf("\nOutput Image:\n");
  for(int i=0; i<28; i++) {
    for(int j=0; j<28; j++) {
      printf("%3d ", output_image[i][j]);
    }
    printf("\n");
  }
  return 0;
}