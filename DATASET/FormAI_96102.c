//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include<stdio.h>

int main() 
{
   int width = 10;   // Set width to 10 pixels
   int height = 10;  // Set height to 10 pixels
   int pixels[height][width];  // 2D array to store the pixel values
   
   // Use nested for-loops to iterate over each pixel and set the value
   for(int i=0; i<height; i++) 
   {
      for(int j=0; j<width; j++) 
      {
         // Set every even row to 1's and odd rows to 0's
         // This creates a checkerboard-like pattern
         if(i%2 == 0) {
            pixels[i][j] = 1;  
         } else {
            pixels[i][j] = 0;  
         }
      }
   }
   
   // Iterate over each pixel and print its value
   for(int i=0; i<height; i++) 
   {
      for(int j=0; j<width; j++) 
      {
         printf("%d ", pixels[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}