//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void main() {

  int R,G,B;
  float C,M,Y,K;

  // Take RGB input from user
  printf("Enter the RGB values (range 0-255): \n");
  scanf("%d %d %d", &R, &G, &B);

  // Convert RGB to CMYK color space
  C = 1 - (R/255.0);
  M = 1 - (G/255.0);
  Y = 1 - (B/255.0);

  float minCMY = fmin(C, fmin(M,Y));
  
  if (minCMY == 1) {
    K = 1;
    C = 0;
    M = 0;
    Y = 0;
  } else {
    K = minCMY;
    C = (C - K) / (1 - K);
    M = (M - K) / (1 - K);
    Y = (Y - K) / (1 - K);
  }

  // Print the equivalent CMYK color code
  printf("\n The equivalent CMYK code is: C=%.2f M=%.2f Y=%.2f K=%.2f", C, M, Y, K);

}