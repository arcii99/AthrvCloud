//FormAI DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
   int r,g,b;
   char input[10];

   printf("Enter a color code in RGB format (ex. 255 0 0 for red): ");
   fgets(input, 10, stdin);

   sscanf(input, "%d %d %d", &r, &g, &b);

   int hex = (r << 16) + (g << 8) + b;

   printf("Color code in hexadecimal format: #%06X", hex);

   return 0;
}