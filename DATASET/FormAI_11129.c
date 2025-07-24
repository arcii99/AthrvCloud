//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generatePixelArt(char pixelArt[][WIDTH]);
void printPixelArt(char pixelArt[][WIDTH]);

int main()
{
  char pixelArt[HEIGHT][WIDTH];

  // seed random number generator
  srand(time(NULL));

  // generate the pixel art
  generatePixelArt(pixelArt);

  // print the pixel art
  printPixelArt(pixelArt);

  return 0;
}

// Generate the pixel art
void generatePixelArt(char pixelArt[][WIDTH])
{
  int i, j;
  char colors[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

  for (i = 0; i < HEIGHT; i++)
  {
    for (j = 0; j < WIDTH; j++)
    {
      pixelArt[i][j] = colors[rand() % 10];
    }
  }
}

// Print the pixel art
void printPixelArt(char pixelArt[][WIDTH])
{
  int i, j;

  for (i = 0; i < HEIGHT; i++)
  {
    for (j = 0; j < WIDTH; j++)
    {
      printf("%c", pixelArt[i][j]);
    }
    printf("\n");
  }
}