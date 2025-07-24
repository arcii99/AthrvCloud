//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>

int main(){
   char colorCode[7];
   int red, green, blue;

   printf("Enter a color code in hexadecimal (e.g. 6F42C7): ");
   scanf("%s", colorCode);

   red = (int)strtol(strncpy(malloc(3), &colorCode[0], 2), NULL, 16);
   green = (int)strtol(strncpy(malloc(3), &colorCode[2], 2), NULL, 16);
   blue = (int)strtol(strncpy(malloc(3), &colorCode[4], 2), NULL, 16);

   printf("\nConverted color:\n");
   printf("- Red: %d\n", red);
   printf("- Green: %d\n", green);
   printf("- Blue: %d\n", blue);

   return 0;
}