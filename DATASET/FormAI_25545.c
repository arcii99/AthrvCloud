//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>

int main()
{
    int red, green, blue;
    printf("Enter the red value (0-255): ");
    scanf("%d", &red);
    printf("Enter the green value (0-255): ");
    scanf("%d", &green);
    printf("Enter the blue value (0-255): ");
    scanf("%d", &blue);

    // Convert RGB to hexadecimal
    int hex = (red << 16) | (green << 8) | blue;

    printf("The hexadecimal color code is #%06X\n", hex);

    return 0;
}