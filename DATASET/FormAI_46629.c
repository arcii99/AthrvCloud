//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main(){

    //Variables to store RGB values
    int r, g, b;

    //Get RGB values from user
    printf("Enter the RGB values (0-255)\n");
    printf("Red: ");
    scanf("%d", &r);
    printf("Green: ");
    scanf("%d", &g);
    printf("Blue: ");
    scanf("%d", &b);

    //Calculate the Hexadecimal values
    int hex1, hex2, hex3;

    hex1 = r / 16;
    hex2 = r % 16;
    hex3 = g / 16;

    printf("The Color Code is #%X%X%X\n", hex1, hex2, hex3);

    return 0;
}