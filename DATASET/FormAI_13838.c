//FormAI DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000
#define MAX_ITERATIONS 1000
#define MAX_COLOR 255
#define MAX_ZOOM 10000

int main()
{
  double c_real, c_imaginary, z_real, z_imaginary, next_z_real, next_z_imaginary, temp;
  int i, j, iteration;
  int escape_time[SIZE][SIZE];
  char image[SIZE][SIZE];
  double x_min = -2.0, x_max = 2.0, y_min = -2.0, y_max = 2.0;
  double x_step = (x_max - x_min) / SIZE;
  double y_step = (y_max - y_min) / SIZE;
  double zoom_factor = 1;
  
  // Generate random complex number
  srand(42);
  c_real = (double)rand() / RAND_MAX * 4.0 - 2.0;
  c_imaginary = (double)rand() / RAND_MAX * 4.0 - 2.0;
  
  // Generate fractal image
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      z_real = x_min + i * x_step;
      z_imaginary = y_min + j * y_step;
      iteration = 0;
      
      // Check escape time
      while (z_real * z_real + z_imaginary * z_imaginary < 4.0 && iteration < MAX_ITERATIONS) {
        next_z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
        next_z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
        z_real = next_z_real;
        z_imaginary = next_z_imaginary;
        iteration++;
      }
      
      // Set pixel color based on escape time
      if (iteration == MAX_ITERATIONS) {
        escape_time[i][j] = -1;
      } else {
        escape_time[i][j] = iteration;
      }
    }
  }
  
  // Normalize escape times and generate image
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (escape_time[i][j] == -1) {
        image[i][j] = ' ';
      } else {
        temp = (double)escape_time[i][j] / MAX_ITERATIONS * MAX_COLOR;
        image[i][j] = (char)round(temp);
      }
    }
  }
  
  // Display fractal image
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }
  
  // Zoom in on random complex number
  while (zoom_factor <= MAX_ZOOM) {
    x_min = c_real - zoom_factor;
    x_max = c_real + zoom_factor;
    y_min = c_imaginary - zoom_factor;
    y_max = c_imaginary + zoom_factor;
    x_step = (x_max - x_min) / SIZE;
    y_step = (y_max - y_min) / SIZE;
    zoom_factor *= 2;
    
    // Generate fractal image
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        z_real = x_min + i * x_step;
        z_imaginary = y_min + j * y_step;
        iteration = 0;

        // Check escape time
        while (z_real * z_real + z_imaginary * z_imaginary < 4.0 && iteration < MAX_ITERATIONS) {
          next_z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
          next_z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
          z_real = next_z_real;
          z_imaginary = next_z_imaginary;
          iteration++;
        }

        // Set pixel color based on escape time
        if (iteration == MAX_ITERATIONS) {
          escape_time[i][j] = -1;
        } else {
          escape_time[i][j] = iteration;
        }
      }
    }

    // Normalize escape times and generate image
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        if (escape_time[i][j] == -1) {
          image[i][j] = ' ';
        } else {
          temp = (double)escape_time[i][j] / MAX_ITERATIONS * MAX_COLOR;
          image[i][j] = (char)round(temp);
        }
      }
    }

    // Display fractal image
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        printf("%c", image[i][j]);
      }
      printf("\n");
    }
  }
  
  return 0;
}