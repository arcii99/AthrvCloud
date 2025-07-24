//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Color Code Converter!\n");

    char hexCode[7];
    printf("Please enter your hex color code (example: #FF5733): ");
    scanf("%s", &hexCode);

    int redValue, greenValue, blueValue;

    sscanf(hexCode, "#%02x%02x%02x", &redValue, &greenValue, &blueValue);

    printf("Here are the RGB values for your color:\n");
    printf("Red: %d\n", redValue);
    printf("Green: %d\n", greenValue);
    printf("Blue: %d\n", blueValue);

    printf("\nNow let's convert those values to CMYK!\n");

    float cValue, mValue, yValue, kValue;

    cValue = ((255 - redValue) / 255.0);
    mValue = ((255 - greenValue) / 255.0);
    yValue = ((255 - blueValue) / 255.0);

    float minCMY = fminf(cValue, fminf(mValue, yValue));

    cValue = (cValue - minCMY) / (1 - minCMY);
    mValue = (mValue - minCMY) / (1 - minCMY);
    yValue = (yValue - minCMY) / (1 - minCMY);
    kValue = minCMY;

    printf("Here are the CMYK values for your color:\n");
    printf("Cyan: %f\n", cValue);
    printf("Magenta: %f\n", mValue);
    printf("Yellow: %f\n", yValue);
    printf("Key (black): %f\n", kValue);

    printf("\nThanks for using the Color Code Converter!");
    return 0;
}