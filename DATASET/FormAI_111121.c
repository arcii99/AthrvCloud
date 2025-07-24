//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

/* The characters for the ASCII art image */
char ASCII_CHARS[] = "$@B%8&WM#*oahkbdpwmZO0QLCJYXzcvnxsu+~<>=-;:,. ";
int NUM_CHARS = sizeof(ASCII_CHARS) / sizeof(char);

/* The threshold values for each ASCII character */
int THRESHOLDS[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250};

/* Function to convert a color image pixel to grayscale */
int colorToGrayscale(int r, int g, int b) {
  return 0.21 * r + 0.72 * g + 0.07 * b;
}

int main(int argc, char *argv[]) {
  /* Open the input file */
  FILE *input_file = fopen(argv[1], "r");

  /* Check if the file was opened successfully */
  if (!input_file) {
    printf("Error: could not open image file '%s'\n", argv[1]);
    exit(1);
  }

  /* Read the image dimensions */
  int width, height;
  fscanf(input_file, "%d %d", &width, &height);

  /* Check if the image is too large */
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: image dimensions too large (max %d x %d)\n", MAX_WIDTH, MAX_HEIGHT);
    exit(1);
  }

  /* Allocate memory for the grayscale pixel grid */
  int (*grayscale_pixels)[height] = malloc(width * sizeof(*grayscale_pixels));

  /* Read the color pixels and convert them to grayscale */
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      int r, g, b;
      fscanf(input_file, "%d %d %d", &r, &g, &b);
      grayscale_pixels[i][j] = colorToGrayscale(r, g, b);
    }
  }

  /* Close the input file */
  fclose(input_file);

  /* Open the output file */
  FILE *output_file = fopen(argv[2], "w");

  /* Check if the file was opened successfully */
  if (!output_file) {
    printf("Error: could not open output file '%s'\n", argv[2]);
    exit(1);
  }

  /* Write the ASCII art to the output file */
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      int grayscale_value = grayscale_pixels[i][j];
      int threshold_index = grayscale_value / 10;
      if (threshold_index >= NUM_CHARS) {
        threshold_index = NUM_CHARS - 1;
      }
      char ascii_char = ASCII_CHARS[threshold_index];
      fputc(ascii_char, output_file);
    }
    fputc('\n', output_file);
  }

  /* Close the output file */
  fclose(output_file);

  /* Free the memory */
  free(grayscale_pixels);

  return 0;
}