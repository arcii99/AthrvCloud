//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 256
#define COLS 256

void flipImage(char *filename, int rows, int cols) {
  FILE *fp = fopen(filename, "rb+");
  if (fp == NULL) {
    printf("Error: File not found");
    exit(1);
  }

  char imgData[ROWS][COLS];
  fread(imgData, sizeof(imgData[0]), rows * cols, fp);

  // Flipping horizontally
  for (int r = 0; r < rows; r++) {
    for (int c1 = 0, c2 = cols - 1; c1 < c2; c1++, c2--) {
      char temp = imgData[r][c1];
      imgData[r][c1] = imgData[r][c2];
      imgData[r][c2] = temp;
    }
  }

  fseek(fp, sizeof(char) * rows * cols, SEEK_SET); // Skip header info
  fwrite(imgData, sizeof(imgData[0]), rows * cols, fp);

  fclose(fp);
}

void adjustBrightness(char *filename, int rows, int cols, int brightness) {
  FILE *fp = fopen(filename, "rb+");
  if (fp == NULL) {
    printf("Error: File not found");
    exit(1);
  }

  char imgData[ROWS][COLS];
  fread(imgData, sizeof(imgData[0]), rows * cols, fp);

  // Adjusting brightness
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int newVal = imgData[r][c] + brightness;
      imgData[r][c] = (newVal > 255) ? 255 : (newVal < 0) ? 0 : newVal; // Clamp values
    }
  }

  fseek(fp, sizeof(char) * rows * cols, SEEK_SET); // Skip header info
  fwrite(imgData, sizeof(imgData[0]), rows * cols, fp);

  fclose(fp);
}

void adjustContrast(char *filename, int rows, int cols, int contrast) {
  FILE *fp = fopen(filename, "rb+");
  if (fp == NULL) {
    printf("Error: File not found");
    exit(1);
  }

  char imgData[ROWS][COLS];
  fread(imgData, sizeof(imgData[0]), rows * cols, fp);

  // Adjusting contrast
  float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int newVal = factor * (imgData[r][c] - 128) + 128;
      imgData[r][c] = (newVal > 255) ? 255 : (newVal < 0) ? 0 : newVal; // Clamp values
    }
  }

  fseek(fp, sizeof(char) * rows * cols, SEEK_SET); // Skip header info
  fwrite(imgData, sizeof(imgData[0]), rows * cols, fp);

  fclose(fp);
}

int main() {
  // Flip image
  flipImage("input_image.bmp", ROWS, COLS);

  // Adjust brightness by adding 50
  adjustBrightness("input_image.bmp", ROWS, COLS, 50);

  // Adjust contrast by increasing it by 50%
  adjustContrast("input_image.bmp", ROWS, COLS, 127);

  return 0;
}