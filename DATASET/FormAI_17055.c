//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>

int main() {
   int red, green, blue, hex;

   printf("Enter the red, green, and blue values separated by spaces: ");
   scanf("%d %d %d", &red, &green, &blue);

   // convert RGB to hex
   hex = (red << 16) | (green << 8) | blue;

   printf("The hex value of the RGB color is: #%06X\n", hex);

   return 0;
}