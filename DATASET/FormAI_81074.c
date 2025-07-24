//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ITERATIONS 1000
#define WIDTH 1000
#define HEIGHT 1000

// Define the complex struct
typedef struct {
  double real;
  double imag;
} complex;

// Define the functions for adding and multiplying complex numbers
complex add(complex num1, complex num2) {
  complex result;
  result.real = num1.real + num2.real;
  result.imag = num1.imag + num2.imag;
  return result;
}

complex multiply(complex num1, complex num2) {
  complex result;
  result.real = num1.real * num2.real - num1.imag * num2.imag;
  result.imag = num1.real * num2.imag + num1.imag * num2.real;
  return result;
}

// Define the color struct for RGB values
typedef struct {
  int r;
  int g;
  int b;
} color;

// Define the image struct
typedef struct {
  color pixels[WIDTH][HEIGHT];
} image;

// Define the main fractal function
void fractal(complex c, image* img) {
  complex z = {0, 0};
  int i;
  for (i = 0; i < ITERATIONS; i++) {
    if (sqrt(z.real * z.real + z.imag * z.imag) > 2) {
      break;
    }
    z = add(multiply(z, z), c);
  }
  double ratio = (double)i / ITERATIONS;
  color rgb = {ratio * 255, ratio * 255, ratio * 255};
  img->pixels[(int)((c.real + 2) / 4 * WIDTH)][(int)((c.imag + 2) / 4 * HEIGHT)] = rgb;
}

// Define the main function
int main() {
  // Create the image and set all pixels to black
  image img;
  int i, j;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      img.pixels[i][j].r = 0;
      img.pixels[i][j].g = 0;
      img.pixels[i][j].b = 0;
    }
  }
  
  // Generate the fractal for each pixel
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      complex c = {(double) i / WIDTH * 4 - 2, (double) j / HEIGHT * 4 - 2};
      fractal(c, &img);
    }
  }
  
  // Write the image to a file
  FILE* f = fopen("fractal.ppm", "wb");
  fprintf(f, "P3 %d %d 255\n", WIDTH, HEIGHT);
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      fprintf(f, "%d %d %d ", img.pixels[i][j].r, img.pixels[i][j].g, img.pixels[i][j].b);
    }
    fprintf(f, "\n");
  }
  fclose(f);
  
  return 0;
}