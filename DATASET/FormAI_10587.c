//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 128
#define HEIGHT 64

char greyscale[] = {'@', '#', '8', '&', '0', 'o', ':', '*', '.', ' '};

struct RGB {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

struct RGB* read_image(char* filename) {
  FILE* fp = fopen(filename, "rb");
  char buf[16];
  fscanf(fp, "%s", buf);
  int width, height, maxval;
  fscanf(fp, "%d %d %d", &width, &height, &maxval);
  struct RGB* pixels = malloc(sizeof(struct RGB) * width * height);
  fread(pixels, sizeof(struct RGB), width * height, fp);
  fclose(fp);
  return pixels;
}

int get_greyscale_index(struct RGB pixel) {
  int avg = (pixel.red + pixel.green + pixel.blue) / 3;
  return (int)(avg / (256.0 / 10));
}

void print_ascii_art(struct RGB* pixels) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int index = i * WIDTH + j;
      int g_index = get_greyscale_index(pixels[index]);
      printf("%c", greyscale[g_index]);
    }
    printf("\n");
  }
}

int main() {
  struct RGB* pixels = read_image("input.ppm");
  print_ascii_art(pixels);
  free(pixels);
  return 0;
}