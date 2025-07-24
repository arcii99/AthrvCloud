//FormAI DATASET v1.0 Category: Image compression ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // image dimensions
  int width = 256;
  int height = 256;

  // read input image
  FILE *input_file = fopen("input.pgm", "rb");
  unsigned char *image = malloc(width * height * sizeof(unsigned char));
  fread(image, sizeof(unsigned char), width * height, input_file);
  fclose(input_file);

  // calculate mean intensity
  int i, j;
  double total_intensity = 0;
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      total_intensity += image[i * width + j];
    }
  }
  double mean_intensity = total_intensity / (width * height);

  // subtract mean intensity and calculate standard deviation
  double total_deviation = 0;
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      double deviation = image[i * width + j] - mean_intensity;
      total_deviation += deviation * deviation;
      image[i * width + j] = (unsigned char)(deviation + 128);
    }
  }
  double standard_deviation = sqrt(total_deviation / (width * height));

  // output compressed image
  FILE *output_file = fopen("output.pgm", "wb");
  fprintf(output_file, "P5\n%d %d\n255\n", width, height);
  fwrite(image, sizeof(unsigned char), width * height, output_file);
  fclose(output_file);

  // display compression information
  printf("Image compression complete!\n");
  printf("Mean intensity: %f\n", mean_intensity);
  printf("Standard deviation: %f\n", standard_deviation);

  return 0;
}