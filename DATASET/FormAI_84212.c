//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
   int n, k;
   float xr[4] = {1.2, 3.7, 5.1, 2.8};
   float xi[4] = {-1.3, 2.2, 0.8, -3.4};

   printf("Original signal: \n");
   for(n = 0; n < 4; n++) {
      printf("%f + j(%f) \n", xr[n], xi[n]);
   }

   float br[4], bi[4] = {0};

   float w = PI/2.0;

   printf("Transformation matrix: \n");
   for(n = 0; n < 4; n++) {
      for(k = 0; k < 4; k++) {
         float re = cos(w*n*k);
         float im = sin(w*n*k);
         printf("%f + j(%f) ", re, im);

         br[n] += (xr[k]*re - xi[k]*im);
         bi[n] += (xr[k]*im + xi[k]*re);
      }
      printf("\n");
   }

   printf("FFT of the signal: \n");
   for(n = 0; n < 4; n++) {
      printf("%f + j(%f) \n", br[n], bi[n]);
   }

   return 0;
}