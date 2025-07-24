//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

int main()
{
  /* Creating a 2D array to store the pixel information */
  int image[WIDTH][HEIGHT];

  /* Initializing the array to all black pixels */
  for(int i=0; i<WIDTH; i++)
    for(int j=0; j<HEIGHT; j++)
      image[i][j] = 0;

  /* Fractal Generation code */
  int x,y;
  for(float t=0; t<=360; t+=0.1)
  {
    x = WIDTH/2 + cos(t)*(WIDTH/2);
    y = HEIGHT/2 + sin(t)*(HEIGHT/2);
    image[x][y] = 255;
  }

  /* Writing the pixel information to a PGM file */
  FILE *fp;
  fp = fopen("fractal.pgm", "wb");
  fprintf(fp, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(image, sizeof(int), WIDTH*HEIGHT, fp);
  fclose(fp);

  printf("Fractal generated successfully!");
  
  return 0;
}