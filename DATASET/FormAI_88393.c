//FormAI DATASET v1.0 Category: Image compression ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8

int main() {
   int image[256][256]; //Assuming input image size of 256x256
   int i, j, k, l, m, n;
   float dctMatrix[BLOCK_SIZE][BLOCK_SIZE], idctMatrix[BLOCK_SIZE][BLOCK_SIZE];
   float alpha = 0.5; //Set alpha value

   //Read input image
   //Code to read input image not included here

   //Initialize DCT and inverse DCT matrices
   for (i = 0; i < BLOCK_SIZE; i++) {
      for (j = 0; j < BLOCK_SIZE; j++) {
         dctMatrix[i][j] = cos((2*i + 1)*j*M_PI/(2*BLOCK_SIZE));
         idctMatrix[i][j] = (i == 0) ? 1.0/sqrt(BLOCK_SIZE) : sqrt(2.0/BLOCK_SIZE)*cos((2*j + 1)*i*M_PI/(2*BLOCK_SIZE));
      }
   }

   //Process image
   for (i = 0; i < 256; i += BLOCK_SIZE) {
      for (j = 0; j < 256; j += BLOCK_SIZE) {
         //Copy block of 8x8 pixels
         int block[BLOCK_SIZE][BLOCK_SIZE];
         for (k = 0; k < BLOCK_SIZE; k++) {
            for (l = 0; l < BLOCK_SIZE; l++) {
               block[k][l] = image[i+k][j+l];
            }
         }

         //Perform DCT transform
         float dctBlock[BLOCK_SIZE][BLOCK_SIZE];
         for (k = 0; k < BLOCK_SIZE; k++) {
            for (l = 0; l < BLOCK_SIZE; l++) {
               dctBlock[k][l] = 0.0;
               for (m = 0; m < BLOCK_SIZE; m++) {
                  for (n = 0; n < BLOCK_SIZE; n++) {
                     dctBlock[k][l] += (float)block[m][n] * dctMatrix[m][k] * dctMatrix[n][l];
                  }
               }
               dctBlock[k][l] *= (1.0/(2.0*BLOCK_SIZE))*((k == 0) ? 1.0 : alpha)*((l == 0) ? 1.0 : alpha);
            }
         }

         //Quantize DCT coefficients
         for (k = 0; k < BLOCK_SIZE; k++) {
            for (l = 0; l < BLOCK_SIZE; l++) {
               dctBlock[k][l] = round(dctBlock[k][l]/10.0);
            }
         }

         //Perform inverse DCT transform
         int idctBlock[BLOCK_SIZE][BLOCK_SIZE];
         for (k = 0; k < BLOCK_SIZE; k++) {
            for (l = 0; l < BLOCK_SIZE; l++) {
               idctBlock[k][l] = 0;
               for (m = 0; m < BLOCK_SIZE; m++) {
                  for (n = 0; n < BLOCK_SIZE; n++) {
                     idctBlock[k][l] += (dctBlock[m][n]*idctMatrix[k][m]*idctMatrix[l][n]);
                  }
               }
               idctBlock[k][l] = round(idctBlock[k][l]);
            }
         }

         //Copy block back to image
         for (k = 0; k < BLOCK_SIZE; k++) {
            for (l = 0; l < BLOCK_SIZE; l++) {
               image[i+k][j+l] = idctBlock[k][l];
            }
         }
      }
   }

   //Write compressed image
   //Code to write compressed image not included here

   //Exit program
   return 0;
}