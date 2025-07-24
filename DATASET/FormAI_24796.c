//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main()
{
    int red, green, blue;
    float cyan, magenta, yellow, black;

    printf("Enter the RGB values (0-255) of the color to convert:\nRed: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // converting RGB to CMYK using mathematical formulas
    cyan = 1 - (red/255.0);
    magenta = 1 - (green/255.0);
    yellow = 1 - (blue/255.0);
    float min_val = fmin(cyan, fmin(magenta, yellow));
    cyan = (cyan - min_val) / (1 - min_val);
    magenta = (magenta - min_val) / (1 - min_val);
    yellow = (yellow - min_val) / (1 - min_val);
    black = min_val;

    printf("\nCyan: %f\nMagenta: %f\nYellow: %f\nBlack: %f\n", cyan, magenta, yellow, black);

    return 0;
}