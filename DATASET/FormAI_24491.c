//FormAI DATASET v1.0 Category: Fractal Generation ; Style: detailed
/* This program generates a fractal image using the Mandelbrot set. 
   It takes in user input to determine the dimensions and resolution of the image. 
   The program then iterates over each pixel in the image and determines whether 
   it is in the Mandelbrot set by recursively computing the function z = z^2 + c. 
   The color of the pixel is determined by the number of iterations it takes to 
   determine whether it is in the set or not. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

void generate_fractal(int width, int height, int max_iterations, double x_min, double x_max, double y_min, double y_max) {
  // Allocate memory for the image
  unsigned char* image = (unsigned char*)malloc(width*height*sizeof(unsigned char));
  
  // Iterate over each pixel in the image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Convert pixel coordinates to complex number
      double complex c = (x_max - x_min) / (width - 1) * x + x_min + I * ((y_max - y_min) / (height - 1) * y + y_min);
      
      // Compute the complex series for this pixel
      double complex z = 0;
      int iterations = 0;
      while (cabs(z) < 2 && iterations < max_iterations) {
        z = z*z + c;
        iterations++;
      }
      
      // Determine the color of the pixel based on number of iterations
      if (iterations == max_iterations) {
        image[y*width+x] = 0;
      } else {
        double smooth_color = (double) iterations - log(log(cabs(z))) / log(2);
        image[y*width+x] = (unsigned char)(smooth_color / max_iterations * 255);
      }
    }
  }
  
  // Output the image to a PGM file
  FILE *fp;
  fp = fopen("fractal.pgm", "wb");
  fprintf(fp, "P5\n%d %d\n%d\n", width, height, 255);
  fwrite(image, sizeof(unsigned char), width*height, fp);
  fclose(fp);
  
  // Free memory allocated for the image
  free(image);  
}

int main() {
  // Get user input for image dimensions and resolution
  int width, height, max_iterations;
  double x_min, x_max, y_min, y_max;
  
  printf("Enter image width: ");
  scanf("%d", &width);
  
  printf("Enter image height: ");
  scanf("%d", &height);
  
  printf("Enter maximum iterations: ");
  scanf("%d", &max_iterations);
  
  printf("Enter x_min: ");
  scanf("%lf", &x_min);
  
  printf("Enter x_max: ");
  scanf("%lf", &x_max);
  
  printf("Enter y_min: ");
  scanf("%lf", &y_min);
  
  printf("Enter y_max: ");
  scanf("%lf", &y_max);
  
  // Generate the fractal
  generate_fractal(width, height, max_iterations, x_min, x_max, y_min, y_max);
  
  return 0;
}