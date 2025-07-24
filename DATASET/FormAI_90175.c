//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int rows = 10;
   int columns = 10;
   int pixelSize = 10;
   
   srand(time(NULL)); // Seed the random number generator with current time
   
   int pixelArt[rows][columns]; // Initialize the pixel art array
   
   // Loop through each row and column and randomly assign a color value
   for(int i=0; i<rows; i++) {
      for(int j=0; j<columns; j++) {
         pixelArt[i][j] = rand() % 2; // 0 for black, 1 for white
      }
   }
   
   // Draw the pixel art on the screen
   for(int i=0; i<rows; i++) {
      for(int j=0; j<columns; j++) {
         for(int k=0; k<pixelSize; k++) {
            for(int l=0; l<pixelSize; l++) {
               if(pixelArt[i][j] == 0) { // Black pixel
                  printf(" ");
               } else { // White pixel
                  printf("#");
               }
            }
         }
      }
      printf("\n"); // Move to the next row
   }

   return 0;
}