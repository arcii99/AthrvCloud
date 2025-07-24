//FormAI DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define image dimensions
#define WIDTH 640
#define HEIGHT 480

// define pixel struct
struct pixel {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

// define image struct
struct image {
  struct pixel pixels[WIDTH][HEIGHT];
};

// initialize a blank image
void initialize(struct image *img) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      img->pixels[x][y].red = 255;
      img->pixels[x][y].green = 255;
      img->pixels[x][y].blue = 255;
    }
  }
}

// draw a black rectangle on the image
void drawRectangle(int x1, int y1, int x2, int y2, struct image *img) {
  for (int x = x1; x <= x2; x++) {
    for (int y = y1; y <= y2; y++) {
      img->pixels[x][y].red = 0;
      img->pixels[x][y].green = 0;
      img->pixels[x][y].blue = 0;
    }
  }
}

// save image to file
void save(struct image *img, char *filename) {
  FILE *fp;
  fp = fopen(filename, "wb");

  // write P6 header
  fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);

  // write pixel data
  for (int y = HEIGHT - 1; y >= 0; y--) {
    for (int x = 0; x < WIDTH; x++) {
      fwrite(&(img->pixels[x][y]), sizeof(struct pixel), 1, fp);
    }
  }

  fclose(fp);
}

int main() {
  struct image img;
  char *filename = "output.ppm";

  // initialize image
  initialize(&img);

  // draw rectangle
  drawRectangle(100, 100, 200, 200, &img);

  // save image to file
  save(&img, filename);

  printf("Image saved to %s\n", filename);

  return 0;
}