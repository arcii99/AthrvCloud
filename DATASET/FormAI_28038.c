//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   // Set the size of the canvas
   int WIDTH = 50;
   int HEIGHT = 20;

   // Define the color palette
   char palette[] = {'*', '#', '@', '$', '%', '&', '?', '!', '+', '-'};

   // Seed the random number generator
   srand(time(NULL));

   // Create the canvas as 2d array
   char pixels[HEIGHT][WIDTH];

   // Set all pixel values to 0, which corresponds to the first color in the palette
   for(int i = 0; i < HEIGHT; i++) {
       for(int j = 0; j < WIDTH; j++) {
           pixels[i][j] = '0';
       }
   }

   // Randomly assign colors to each position in the canvas
   for(int i = 0; i < HEIGHT; i++) {
       for(int j = 0; j < WIDTH; j++) {
           pixels[i][j] = palette[rand() % 10];
       }
   }

   // Display the resulting pixel art
   for(int i = 0; i < HEIGHT; i++) {
       for(int j = 0; j < WIDTH; j++) {
           printf("%c", pixels[i][j]);
       }
       printf("\n");
   }

   return 0;
}