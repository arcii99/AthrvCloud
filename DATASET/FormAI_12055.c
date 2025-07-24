//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Brave Style Image Compression Program

int main()
{
   //Initializing variables and arrays
   int height = 512;
   int width = 512;
   int image[height][width]; //2D Array for storing the original image
   int compressed_image[height/2][width/2]; //2D Array for storing the compressed image
   int i, j; //Loop variables

   //Reading the Original Image
   FILE *f = fopen("original_image.raw","rb");
   fread(image, sizeof(image), 1, f);
   fclose(f);

   //Printing the Original Image
   printf("Original Image:\n\n");
   for(i=0; i<height; i++)
   {
      for(j=0; j<width; j++)
      {
         printf("%d ",image[i][j]);
      }
      printf("\n");
   }

   //Compressing the Image
   for(i=0; i<height; i+=2)
   {
      for(j=0; j<width; j+=2)
      {
         compressed_image[i/2][j/2] = (image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1])/4;
      }
   }

   //Printing the Compressed Image
   printf("\n\nCompressed Image:\n\n");
   for(i=0; i<height/2; i++)
   {
      for(j=0; j<width/2; j++)
      {
         printf("%d ",compressed_image[i][j]);
      }
      printf("\n");
   }

   //Calculating Compression Ratio
   double original_size = height*width*sizeof(int);
   double compressed_size = (height/2)*(width/2)*sizeof(int);
   double compression_ratio = original_size/compressed_size;

   //Printing Compression Ratio
   printf("\n\nCompression Ratio: %lf\n",compression_ratio);

   return 0;
}