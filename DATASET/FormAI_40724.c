//FormAI DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define image dimensions
#define HEIGHT 512
#define WIDTH 512
// Define maximum pixel value for each color channel
#define MAX_RGB 255

// Find color channel value clamped between 0 and 255
int clamp(int val) {
  if (val < 0) {
    return 0;
  } else if (val > MAX_RGB) {
    return MAX_RGB;
  } else {
    return val;
  }
}

// Create new image with specified dimensions
void create_image(unsigned char img[HEIGHT][WIDTH][3], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      img[i][j][0] = MAX_RGB; // Set red channel value to 255
      img[i][j][1] = MAX_RGB; // Set green channel value to 255
      img[i][j][2] = MAX_RGB; // Set blue channel value to 255
    }
  }
}

// Convert image to grayscale
void grayscale(unsigned char img[HEIGHT][WIDTH][3], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Compute grayscale value and set all color channels to it
      unsigned char gray = (0.21 * img[i][j][0]) + (0.72 * img[i][j][1]) + (0.07 * img[i][j][2]);
      img[i][j][0] = gray;
      img[i][j][1] = gray;
      img[i][j][2] = gray;
    }
  }
}

// Apply sepia filter to image
void sepia(unsigned char img[HEIGHT][WIDTH][3], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Compute sepia values for each color channel
      int red = (0.393 * img[i][j][0]) + (0.769 * img[i][j][1]) + (0.189 * img[i][j][2]);
      int green = (0.349 * img[i][j][0]) + (0.686 * img[i][j][1]) + (0.168 * img[i][j][2]);
      int blue = (0.272 * img[i][j][0]) + (0.534 * img[i][j][1]) + (0.131 * img[i][j][2]);
      // Set color channels to sepia values clamped between 0 and 255
      img[i][j][0] = clamp(red);
      img[i][j][1] = clamp(green);
      img[i][j][2] = clamp(blue);
    }
  }
}

// Effectively adjust the brightness of the image by adding value to all color channels
void adjust_brightness(unsigned char img[HEIGHT][WIDTH][3], int height, int width, int value) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Add brightness value to each color channel clamped between 0 and 255
      img[i][j][0] = clamp(img[i][j][0] + value);
      img[i][j][1] = clamp(img[i][j][1] + value);
      img[i][j][2] = clamp(img[i][j][2] + value);
    }
  }
}

// Flip the image horizontally
void flip_horizontal(unsigned char img[HEIGHT][WIDTH][3], int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width/2; j++) {
      // Swap pixels across the vertical axis
      unsigned char tmp_r = img[i][j][0];
      unsigned char tmp_g = img[i][j][1];
      unsigned char tmp_b = img[i][j][2];
      img[i][j][0] = img[i][width-j-1][0];
      img[i][j][1] = img[i][width-j-1][1];
      img[i][j][2] = img[i][width-j-1][2];
      img[i][width-j-1][0] = tmp_r;
      img[i][width-j-1][1] = tmp_g;
      img[i][width-j-1][2] = tmp_b;
    }
  }
}

// Flip the image vertically
void flip_vertical(unsigned char img[HEIGHT][WIDTH][3], int height, int width) {
  for (int i = 0; i < height/2; i++) {
    for (int j = 0; j < width; j++) {
      // Swap pixels across the horizontal axis
      unsigned char tmp_r = img[i][j][0];
      unsigned char tmp_g = img[i][j][1];
      unsigned char tmp_b = img[i][j][2];
      img[i][j][0] = img[height-i-1][j][0];
      img[i][j][1] = img[height-i-1][j][1];
      img[i][j][2] = img[height-i-1][j][2];
      img[height-i-1][j][0] = tmp_r;
      img[height-i-1][j][1] = tmp_g;
      img[height-i-1][j][2] = tmp_b;
    }
  }
}

int main(void) {
  // Allocate memory for image
  unsigned char (*image)[WIDTH][3] = malloc(sizeof(unsigned char[HEIGHT][WIDTH][3]));
  if (image == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }

  // Create new image with white color
  create_image(image, HEIGHT, WIDTH);

  // Convert image to grayscale
  grayscale(image, HEIGHT, WIDTH);

  // Apply sepia filter to image
  sepia(image, HEIGHT, WIDTH);

  // Increase brightness by 50
  adjust_brightness(image, HEIGHT, WIDTH, 50);

  // Flip image horizontally
  flip_horizontal(image, HEIGHT, WIDTH);

  // Flip image vertically
  flip_vertical(image, HEIGHT, WIDTH);

  // Output image as PPM format
  FILE *fp = fopen("image.ppm", "wb");
  fprintf(fp, "P6\n%d %d %d\n", WIDTH, HEIGHT, MAX_RGB);
  fwrite(image, sizeof(unsigned char), HEIGHT*WIDTH*3, fp);
  fclose(fp);

  // Free memory for image
  free(image);

  return 0;
}