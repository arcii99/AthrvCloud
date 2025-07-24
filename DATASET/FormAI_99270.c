//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>

// function to convert RGB values to grayscale
int rgbToGrayscale(int red, int green, int blue) {
  return 0.2989 * red + 0.5870 * green + 0.1140 * blue;
}

// function to convert grayscale to ASCII character
char grayscaleToChar(int grayscale) {
  char c;
  if (grayscale >= 230) {
    c = ' ';
  } else if (grayscale >= 200) {
    c = '.';
  } else if (grayscale >= 180) {
    c = ':';
  } else if (grayscale >= 160) {
    c = 'o';
  } else if (grayscale >= 130) {
    c = '&';
  } else if (grayscale >= 100) {
    c = '8';
  } else if (grayscale >= 70) {
    c = '#';
  } else {
    c = '@';
  }
  return c;
}

// function to print out ASCII art from image
void printAsciiArt(char *filename) {
  FILE *imageFile = fopen(filename, "rb");
  char ch;
  int red, green, blue, grayscale;
  while ((ch = fgetc(imageFile)) != EOF) {
    red = (int) ch;
    green = (int) fgetc(imageFile);
    blue = (int) fgetc(imageFile);
    grayscale = rgbToGrayscale(red, green, blue);
    putchar(grayscaleToChar(grayscale));
  }
  fclose(imageFile);
}

int main() {
  printAsciiArt("image.jpg");
  return 0;
}