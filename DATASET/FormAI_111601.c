//FormAI DATASET v1.0 Category: Image Classification system ; Style: shocked
#include <stdio.h>

int main() {
  // Declare variables
  int input_image[28][28];
  int pixel_sum = 0;

  // Read input image from file
  FILE *fp;
  fp = fopen("input_image.txt", "r");
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 28; j++) {
      fscanf(fp, "%d", &input_image[i][j]);
    }
  }

  // Calculate sum of all pixels in the input image
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 28; j++) {
      pixel_sum += input_image[i][j];
    }
  }

  // Classify the image based on pixel sum
  if (pixel_sum < 15000) {
    printf("The input image is a handwritten digit 0.");
  } else if (pixel_sum < 20000) {
    printf("The input image is a handwritten digit 1.");
  } else if (pixel_sum < 25000) {
    printf("The input image is a handwritten digit 2.");
  } else if (pixel_sum < 30000) {
    printf("The input image is a handwritten digit 3.");
  } else if (pixel_sum < 35000) {
    printf("The input image is a handwritten digit 4.");
  } else if (pixel_sum < 40000) {
    printf("The input image is a handwritten digit 5.");
  } else if (pixel_sum < 45000) {
    printf("The input image is a handwritten digit 6.");
  } else if (pixel_sum < 50000) {
    printf("The input image is a handwritten digit 7.");
  } else if (pixel_sum < 55000) {
    printf("The input image is a handwritten digit 8.");
  } else {
    printf("The input image is a handwritten digit 9.");
  }

  return 0;
}