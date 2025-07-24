//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int hexNumber, red, green, blue;
  
    printf("Enter a value in hexadecimal format (32 bit): ");
    scanf("%x", &hexNumber);

    red = (hexNumber >> 16) & 0xFF;
    green = (hexNumber >> 8) & 0xFF;
    blue = hexNumber & 0xFF;

    printf("\nIn RGB format: (%d, %d, %d)\n", red, green, blue);

    float redFloat = red / 255.0;
    float greenFloat = green / 255.0;
    float blueFloat = blue / 255.0;

    printf("\nIn decimal format: (%0.2f, %0.2f, %0.2f)\n", redFloat, greenFloat, blueFloat);

    return 0;
}