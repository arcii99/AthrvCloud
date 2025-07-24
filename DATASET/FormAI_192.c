//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

typedef struct {
  int red;
  int green;
  int blue;
} RGB_pixel;

typedef struct {
  RGB_pixel **pixels;
  int width;
  int height;
} Image;

void read_image(char *filename, Image *image) {
  FILE *file;
  char magic_number[3];
  int i, j;

  file = fopen(filename, "r");

  fgets(magic_number, 3, file);

  if (strcmp(magic_number, "P3")) {
    printf("Error: Invalid input file format.\n");
    exit(1);
  }

  fscanf(file, "%d %d", &image->width, &image->height);

  int max_pixel_value;
  fscanf(file, "%d", &max_pixel_value);

  if (max_pixel_value > MAX_PIXEL_VALUE) {
    printf("Error: Invalid pixel value in input file.\n");
    exit(1);
  }

  image->pixels = malloc(image->height * sizeof(RGB_pixel *));
  for (i = 0; i < image->height; i++) {
    image->pixels[i] = malloc(image->width * sizeof(RGB_pixel));
    for (j = 0; j < image->width; j++) {
      RGB_pixel pixel;
      fscanf(file, "%d %d %d", &pixel.red, &pixel.green, &pixel.blue);
      if (pixel.red > max_pixel_value || pixel.green > max_pixel_value || pixel.blue > max_pixel_value) {
        printf("Error: Invalid pixel value.\n");
        exit(1);
      }
      image->pixels[i][j] = pixel;
    }
  }

  fclose(file);
}

void write_image(char *filename, Image *image) {
  FILE *file;
  int i, j;

  file = fopen(filename, "w");

  fprintf(file, "P3\n");
  fprintf(file, "%d %d\n", image->width, image->height);
  fprintf(file, "%d\n", MAX_PIXEL_VALUE);

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      fprintf(file, "%d %d %d ", image->pixels[i][j].red, image->pixels[i][j].green, image->pixels[i][j].blue);
    }
    fprintf(file, "\n");
  }

  fclose(file);
}

void grayscale(Image *image) {
  int i, j;

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      int average = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
      image->pixels[i][j].red = average;
      image->pixels[i][j].green = average;
      image->pixels[i][j].blue = average;
    }
  }
}

void invert_colors(Image *image) {
  int i, j;

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      image->pixels[i][j].red = MAX_PIXEL_VALUE - image->pixels[i][j].red;
      image->pixels[i][j].green = MAX_PIXEL_VALUE - image->pixels[i][j].green;
      image->pixels[i][j].blue = MAX_PIXEL_VALUE - image->pixels[i][j].blue;
    }
  }
}

void apply_gamma_correction(Image *image, float gamma) {
  int i, j;

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      image->pixels[i][j].red = pow(image->pixels[i][j].red / (float) MAX_PIXEL_VALUE, gamma) * MAX_PIXEL_VALUE;
      image->pixels[i][j].green = pow(image->pixels[i][j].green / (float) MAX_PIXEL_VALUE, gamma) * MAX_PIXEL_VALUE;
      image->pixels[i][j].blue = pow(image->pixels[i][j].blue / (float) MAX_PIXEL_VALUE, gamma) * MAX_PIXEL_VALUE;
    }
  }
}

int main() {
  Image image;
  read_image("input.ppm", &image);
  grayscale(&image);
  write_image("grayscale.ppm", &image);
  invert_colors(&image);
  write_image("invert_colors.ppm", &image);
  apply_gamma_correction(&image, 0.5);
  write_image("gamma_correction.ppm", &image);

  int i;

  for (i = 0; i < image.height; i++) {
    free(image.pixels[i]);
  }
  free(image.pixels);

  return 0;
}