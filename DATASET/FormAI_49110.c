//FormAI DATASET v1.0 Category: Image compression ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read in the input image file
  FILE *input_file = fopen("input_image.ppm", "rb");
  if (input_file == NULL) {
    printf("Error reading input file\n");
    return 1;
  }

  // Read in the header for the image file
  char header[3];
  fscanf(input_file, "%s\n", header);
  int width, height, max_value;
  fscanf(input_file, "%d %d\n%d\n", &width, &height, &max_value);

  // Allocate memory for the image pixels
  unsigned char *pixels = (unsigned char *)malloc(sizeof(unsigned char) * width * height * 3);

  // Read in the pixel data
  fread(pixels, sizeof(unsigned char), width * height * 3, input_file);

  // Perform image compression

  // Write out the compressed image file
  FILE *output_file = fopen("compressed_image.ppm", "wb");
  if (output_file == NULL) {
    printf("Error writing output file\n");
    return 1;
  }

  // Write out the header for the image file
  fprintf(output_file, "P6\n%d %d\n%d\n", width, height, max_value);

  // Write out the compressed pixel data
  fwrite(pixels, sizeof(unsigned char), width * height * 3, output_file);

  // Clean up memory and close files
  free(pixels);
  fclose(input_file);
  fclose(output_file);

  return 0;
}