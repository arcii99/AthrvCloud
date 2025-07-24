//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define constants for colors
#define BLACK 0
#define WHITE 255

// Define constants for window size
#define WIDTH 800
#define HEIGHT 800

// Define constants for the fractal
#define MAX_ITERATIONS 100
#define PIXELS_PER_UNIT 40
#define ZOOM_FACTOR 0.95

// Define image array and function to write to file
unsigned char image[HEIGHT][WIDTH];
void write_image(char *filename);

// Define function to generate fractal
void generate_fractal(double x, double y, double size, int level);

int main()
{
  // Initialize random seed
  srand(time(NULL));
  
  // Generate fractal starting at origin with size 4
  generate_fractal(0, 0, 4, 0);
  
  // Write image to file
  write_image("fractal.pgm");
  
  return 0;
}

void generate_fractal(double x, double y, double size, int level)
{
  // Base case: level exceeds maximum iterations
  if (level > MAX_ITERATIONS)
    return;

  // Loop through the image array and set pixel values
  for (int i = x * PIXELS_PER_UNIT + WIDTH / 2 - size * PIXELS_PER_UNIT / 2; i < x * PIXELS_PER_UNIT + WIDTH / 2 + size * PIXELS_PER_UNIT / 2; i++)
  {
    for (int j = y * PIXELS_PER_UNIT + HEIGHT / 2 - size * PIXELS_PER_UNIT / 2; j < y * PIXELS_PER_UNIT + HEIGHT / 2 + size * PIXELS_PER_UNIT / 2; j++)
    {
      // Generate random number between 0 and 1
      double r = (double)rand() / RAND_MAX;
      
      // Color pixel black or white based on random number
      if (r < pow(ZOOM_FACTOR, level))
        image[j][i] = BLACK;
      else
        image[j][i] = WHITE;
    }
  }
  
  // Generate subfractals recursively
  generate_fractal(x - size / 2, y - size / 2, size * ZOOM_FACTOR, level + 1);
  generate_fractal(x + size / 2, y - size / 2, size * ZOOM_FACTOR, level + 1);
  generate_fractal(x - size / 2, y + size / 2, size * ZOOM_FACTOR, level + 1);
  generate_fractal(x + size / 2, y + size / 2, size * ZOOM_FACTOR, level + 1);
}

void write_image(char *filename)
{
  FILE *file = fopen(filename, "wb");
  fprintf(file, "P5 %d %d %d ", WIDTH, HEIGHT, 255);
  fwrite(image, 1, WIDTH * HEIGHT, file);
  fclose(file);
}