//FormAI DATASET v1.0 Category: Image Editor ; Style: excited
// Welcome to the coolest C Image Editor program ever!
// Get ready for some pixel-perfect editing action!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define PIXEL_SIZE 3

int main() {
  char filename[MAX_FILENAME_LENGTH];
  printf("Enter filename: ");
  scanf("%s", filename);
  
  // Open the image file
  FILE *in_file = fopen(filename, "rb");
  
  // Check if the file exists
  if (in_file == NULL) {
    printf("File not found :(");
    return 1;
  }
  
  // Read the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, in_file);
  fread(&height, sizeof(int), 1, in_file);

  // Allocate memory for the pixel data
  unsigned char *pixels = (unsigned char *)malloc(width * height * PIXEL_SIZE);

  // Read the pixel data from the file
  fread(pixels, sizeof(unsigned char), width * height * PIXEL_SIZE, in_file);

  // Close the input file
  fclose(in_file);

  // RGBA to grayscale conversion
  for (int i = 0; i < width * height; i++) {
    unsigned char r = pixels[i * PIXEL_SIZE];
    unsigned char g = pixels[i * PIXEL_SIZE + 1];
    unsigned char b = pixels[i * PIXEL_SIZE + 2];

    unsigned char gray = (unsigned char)(0.2989 * r + 0.5870 * g + 0.1140 * b);

    pixels[i * PIXEL_SIZE] = gray;
    pixels[i * PIXEL_SIZE + 1] = gray;
    pixels[i * PIXEL_SIZE + 2] = gray;
  }

  // Create a new file for the grayscale image
  char output_filename[MAX_FILENAME_LENGTH];
  strncpy(output_filename, filename, strlen(filename) - 4);
  strcat(output_filename, "_grayscale.bmp");
  
  // Open the output file
  FILE *out_file = fopen(output_filename, "wb");

  // Write the file header
  fwrite("BM", sizeof(char), 2, out_file);
  int file_size = sizeof(int) * 3 + width * height * PIXEL_SIZE;
  fwrite(&file_size, sizeof(int), 1, out_file);
  int reserved = 0;
  fwrite(&reserved, sizeof(int), 1, out_file);
  int data_offset = sizeof(int) * 3 + 2;
  fwrite(&data_offset, sizeof(int), 1, out_file);

  // Write the info header
  int info_header_size = 40;
  fwrite(&info_header_size, sizeof(int), 1, out_file);
  fwrite(&width, sizeof(int), 1, out_file);
  fwrite(&height, sizeof(int), 1, out_file);
  short planes = 1;
  fwrite(&planes, sizeof(short), 1, out_file);
  short bits_per_pixel = 24;
  fwrite(&bits_per_pixel, sizeof(short), 1, out_file);
  int compression = 0;
  fwrite(&compression, sizeof(int), 1, out_file);
  int image_size = 0;
  fwrite(&image_size, sizeof(int), 1, out_file);
  int h_resolution = 2835;
  fwrite(&h_resolution, sizeof(int), 1, out_file);
  int v_resolution = 2835;
  fwrite(&v_resolution, sizeof(int), 1, out_file);
  int num_colors = 0;
  fwrite(&num_colors, sizeof(int), 1, out_file);
  int important_colors = 0;
  fwrite(&important_colors, sizeof(int), 1, out_file);

  // Write the pixel data
  fwrite(pixels, sizeof(unsigned char), width * height * PIXEL_SIZE, out_file);

  // Close the output file
  fclose(out_file);

  // Free the memory allocated for the pixel data
  free(pixels);

  printf("Success! Converted %s to grayscale and saved it as %s :)", filename, output_filename);
  return 0;
}