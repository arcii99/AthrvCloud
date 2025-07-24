//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include<stdio.h>
#include<string.h>

int main(){

    char hex[10], red_hex[2], green_hex[2], blue_hex[2];
    int red_dec, green_dec, blue_dec;

    printf("Enter the hexadecimal color code: ");
    scanf("%s", hex);

    //Extracting red, green, and blue values from the hexadecimal code
    red_hex[0] = hex[1];
    red_hex[1] = hex[2];
    green_hex[0] = hex[3];
    green_hex[1] = hex[4];
    blue_hex[0] = hex[5];
    blue_hex[1] = hex[6];

    //Converting the red, green, and blue hexadecimal codes to decimal values
    sscanf(red_hex, "%2x", &red_dec);
    sscanf(green_hex, "%2x", &green_dec);
    sscanf(blue_hex, "%2x", &blue_dec);

    //Printing the decimal values of the color components
    printf("\nRed: %d", red_dec);
    printf("\nGreen: %d", green_dec);
    printf("\nBlue: %d", blue_dec);

    //Converting decimal values of color components to percentage values
    float red_percent = red_dec * 100.0 / 255.0;
    float green_percent = green_dec * 100.0 / 255.0;
    float blue_percent = blue_dec * 100.0 / 255.0;

    //Printing the percentage values of the color components
    printf("\n\nRed: %.2f %%", red_percent);
    printf("\nGreen: %.2f %%", green_percent);
    printf("\nBlue: %.2f %%", blue_percent);

    return 0;
}