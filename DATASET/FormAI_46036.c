//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(int c)
{
    char* hex = malloc(sizeof(char) * 7);
    sprintf(hex, "#%02X%02X%02X", (c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
    return hex;
}

int main()
{
    int red, green, blue, color;
    char* hex;

    printf("Enter the red component (0-255):\n");
    scanf("%d", &red);

    printf("Enter the green component (0-255):\n");
    scanf("%d", &green);

    printf("Enter the blue component (0-255):\n");
    scanf("%d", &blue);

    color = (red << 16) | (green << 8) | blue;

    hex = convert(color);

    printf("The color is: %s\n", hex);

    free(hex);

    return 0;
}