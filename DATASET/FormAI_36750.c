//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct Pixel {
  unsigned char r, g, b;
};

struct Image {
  int width, height;
  struct Pixel *pixels;
};

void read_png_file(char* file_name, struct Image *img) {
  // code to read PNG file and populate img struct
}

void write_png_file(char* file_name, struct Image *img) {
  // code to write PNG file from img struct
}

void grayscale(struct Image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      struct Pixel *p = &(img->pixels[i*img->width+j]);
      unsigned char gray = (p->r + p->g + p->b) / 3;
      p->r = gray;
      p->g = gray;
      p->b = gray;
    }
  }
}

void invert_colors(struct Image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      struct Pixel *p = &(img->pixels[i*img->width+j]);
      p->r = 255 - p->r;
      p->g = 255 - p->g;
      p->b = 255 - p->b;
    }
  }
}

int main(int argc, char** argv) {
  struct Image img;
  read_png_file(argv[1], &img);

  grayscale(&img);
  write_png_file("grayscale.png", &img);

  invert_colors(&img);
  write_png_file("inverted_colors.png", &img);

  free(img.pixels);
  return 0;
}