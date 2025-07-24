//FormAI DATASET v1.0 Category: Image compression ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel {
  unsigned char r, g, b;
} Pixel;

// Function to read and store pixel values from input file
Pixel* read_pixels(const char* filename, int* width, int* height) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: Unable to open file %s\n", filename);
    exit(1);
  }

  int header_size = 54;
  unsigned char header[header_size];

  // Read the BMP header
  if (fread(header, sizeof(unsigned char), header_size, fp) != header_size) {
    fprintf(stderr, "Error: Invalid BMP header in file %s\n", filename);
    fclose(fp);
    exit(1);
  }

  // Check that file format is BMP
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: Invalid BMP file format in file %s\n", filename);
    fclose(fp);
    exit(1);
  }

  *width = *(int*)&header[18];
  *height = *(int*)&header[22];
  int bpp = *(int*)&header[28];

  if (bpp != 24) {
    fprintf(stderr, "Error: Unsupported BMP color depth in file %s\n", filename);
    fclose(fp);
    exit(1);
  }

  int padding = (*width * 3) % 4;
  if (padding > 0) {
    padding = 4 - padding;
  }

  int size = (*width * 3 + padding) * *height;
  Pixel* pixels = (Pixel*) malloc(size);

  // Read the pixel values
  unsigned char* buf = (unsigned char*) pixels;
  int i;
  for (i = 0; i < size; i++) {
    buf[i] = fgetc(fp);
  }

  fclose(fp);

  return pixels;
}

// Function to write pixel values to output file
void write_pixels(const char* filename, const Pixel* pixels, int width, int height) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: Unable to open file %s for writing\n", filename);
    exit(1);
  }

  int header_size = 54;
  unsigned char header[header_size];
  int file_size = header_size + width * height * 3;
  int padding = (width * 3) % 4;
  if (padding > 0) {
    padding = 4 - padding;
  }

  header[0] = 'B';
  header[1] = 'M';
  *(int*)&header[2] = file_size;
  *(int*)&header[10] = header_size;
  *(int*)&header[14] = 40;
  *(int*)&header[18] = width;
  *(int*)&header[22] = height;
  *(short*)&header[26] = 1;
  *(short*)&header[28] = 24;
  *(int*)&header[34] = width * height * 3;
  fwrite(header, sizeof(unsigned char), header_size, fp);

  int row_size = width * 3 + padding;
  unsigned char* buf = (unsigned char*) pixels;
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < row_size; j++) {
      fputc(buf[i * row_size + j], fp);
    }
  }

  fclose(fp);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(1);
  }

  int width, height;
  Pixel* pixels = read_pixels(argv[1], &width, &height);

  // Compress the image
  int i;
  for (i = 0; i < width * height; i++) {
    pixels[i].r &= 0xE0; // Keep the upper 3 bits of the red component
    pixels[i].g &= 0xE0; // Keep the upper 3 bits of the green component
    pixels[i].b &= 0xE0; // Keep the upper 3 bits of the blue component
  }

  write_pixels(argv[2], pixels, width, height);

  free(pixels);

  printf("Image compressed successfully!\n");

  return 0;
}