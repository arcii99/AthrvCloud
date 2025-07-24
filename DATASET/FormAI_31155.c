//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
/* Woohoo! Let's generate some fractals! */
#include <stdio.h>
#include <stdbool.h>

/* Set up some constants */
#define WIDTH 80
#define HEIGHT 25
#define MIN_X -2.0
#define MAX_X 1.0
#define MIN_Y -1.0
#define MAX_Y 1.0

/* Function protypes */
int mandelbrot(double x, double y);
void print_fractal(int fractal[WIDTH][HEIGHT]);
bool is_in_bounds(int x, int y);

/* Wow the user with the main function */
int main() {
  // Generate a 2D array to hold the fractal
  int fractal[WIDTH][HEIGHT];

  // Loop through all the pixels in the array
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      // Calculate the corresponding coordinates in the complex plane
      double real = (double)x / WIDTH * (MAX_X - MIN_X) + MIN_X;
      double imaginary = (double)y / HEIGHT * (MAX_Y - MIN_Y) + MIN_Y;

      // Calculate the Mandelbrot value for this point
      fractal[x][y] = mandelbrot(real, imaginary);
    }
  }

  // Print that fractal!
  print_fractal(fractal);

  return 0;
}

/* The Mandelbrot function */
int mandelbrot(double x, double y) {
  // Set up some variables
  double real = x;
  double imaginary = y;
  int iterations = 0;

  // Run the Mandelbrot algorithm
  while (real * real + imaginary * imaginary <= 4 && iterations < 1000) {
    double temp = real * real - imaginary * imaginary + x;
    imaginary = 2 * real * imaginary + y;
    real = temp;
    iterations++;
  }

  // Return the number of iterations it took to escape
  return iterations;
}

/* A function to print the fractal */
void print_fractal(int fractal[WIDTH][HEIGHT]) {
  // Loop through all the pixels in the array
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Check if this pixel is in bounds
      if (is_in_bounds(x, y)) {
        // If it is, print a space or a character based on the value of the Mandelbrot function
        if (fractal[x][y] < 10) {
          printf(" ");
        } else if (fractal[x][y] < 20) {
          printf(".");
        } else if (fractal[x][y] < 30) {
          printf(":");
        } else if (fractal[x][y] < 40) {
          printf("o");
        } else if (fractal[x][y] < 50) {
          printf("O");
        } else {
          printf("#");
        }
      } else {
        // If it's not in bounds, just print a space
        printf(" ");
      }
    }

    // Print a newline character at the end of each row
    printf("\n");
  }
}

/* A function to check if a pixel is in bounds */
bool is_in_bounds(int x, int y) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    return true;
  } else {
    return false;
  }
}