//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>

int main() {
   int colorCode;

   printf("Enter a color code (0-255): ");
   scanf("%d", &colorCode);

   // Convert color code to RGB values
   int red = colorCode / 65536;
   int green = (colorCode / 256) % 256;
   int blue = colorCode % 256;

   // Print RGB values
   printf("Red value: %d\n", red);
   printf("Green value: %d\n", green);
   printf("Blue value: %d\n", blue);

   return 0;
}