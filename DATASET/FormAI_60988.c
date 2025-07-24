//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

// struct to store image data
typedef struct {
  int width;
  int height;
  unsigned char data[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} image;

// function to read image data from file
void read_image(const char* filename, image* img) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Failed to open image file %s\n", filename);
    exit(1);
  }
  char format[3];
  int width, height, max_val;
  fscanf(fp, "%s\n%d %d\n%d\n", format, &width, &height, &max_val);
  if (strcmp(format, "P5") != 0 || width > MAX_IMAGE_SIZE || height > MAX_IMAGE_SIZE || max_val != 255) {
    printf("Invalid image format or size\n");
    exit(1);
  }
  img->width = width;
  img->height = height;
  fread(img->data, 1, width * height, fp);
  fclose(fp);
}

// function to write image data to file
void write_image(const char* filename, const image* img) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Failed to open image file %s\n", filename);
    exit(1);
  }
  fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, 255);
  fwrite(img->data, 1, img->width * img->height, fp);
  fclose(fp);
}

// function to flip image horizontally
void flip_horizontal(image* img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width / 2; j++) {
      unsigned char tmp = img->data[i][j];
      img->data[i][j] = img->data[i][img->width - 1 - j];
      img->data[i][img->width - 1 - j] = tmp;
    }
  }
}

// function to change image brightness by a factor
void change_brightness(image* img, float factor) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      int val = img->data[i][j] * factor;
      if (val < 0) {
        val = 0;
      }
      if (val > 255) {
        val = 255;
      }
      img->data[i][j] = val;
    }
  }
}

// function to change image contrast by a factor
void change_contrast(image* img, float factor) {
  float average = 0.0f;
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      average += img->data[i][j];
    }
  }
  average /= img->width * img->height;
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      float val = (float) img->data[i][j] - average;
      val *= factor;
      val += average;
      if (val < 0) {
        val = 0;
      }
      if (val > 255) {
        val = 255;
      }
      img->data[i][j] = (unsigned char) val;
    }
  }
}

int main() {
  image img;
  read_image("input.pgm", &img);
  flip_horizontal(&img);
  change_brightness(&img, 1.5f);
  change_contrast(&img, 0.5f);
  write_image("output.pgm", &img);
  return 0;
}