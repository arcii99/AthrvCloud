//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
   int width, height, maxval;
   // Read PPM file header
   scanf("P3 %d %d %d", &width, &height, &maxval);
   printf("Image Width: %d \nImage Height: %d \nMax Value: %d \n", width, height, maxval);
   
   // Allocate memory to store image pixel data
   int **image = (int **)malloc(height * sizeof(int *));
   for(int i = 0; i < height; i++)
      image[i] = (int *)malloc(width * 3 * sizeof(int));
   
   // Read pixel data from input PPM file
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width*3; j++) {
         scanf("%d", &image[i][j]);
      }
   }
   
   // Perform image classification
   int count_red = 0, count_green = 0, count_blue = 0;
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width*3; j += 3) {
         if(image[i][j] > 200 && image[i][j+1] < 100 && image[i][j+2] < 100)
            count_red++;
         else if(image[i][j] < 100 && image[i][j+1] > 200 && image[i][j+2] < 100)
            count_green++;
         else if(image[i][j] < 100 && image[i][j+1] < 100 && image[i][j+2] > 200)
            count_blue++;
      }
   }
   
   // Print image classification results
   printf("Number of Red Pixels: %d \nNumber of Green Pixels: %d \nNumber of Blue Pixels: %d \n", count_red, count_green, count_blue);

   // Free memory allocated for image pixel data
   for(int i = 0; i < height; i++)
      free(image[i]);
   free(image);
   
   return 0;
}