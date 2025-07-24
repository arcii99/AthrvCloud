//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Define variables
   int width, height, color;
   // Seed randomizer
   srand(time(NULL));

   // Get user input for width and height of pixel art
   printf("Enter the width of the pixel art: ");
   scanf("%d", &width);
   printf("Enter the height of the pixel art: ");
   scanf("%d", &height);

   // Generate pixel art
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         // Generate random color value
         color = rand() % 2;
         // Print color to console
         if(color == 0) {
            printf("\033[47m ");
         } else {
            printf("\033[40m ");
         }
      }
      printf("\033[0m\n");
   }

   // Exit program
   return 0;
}