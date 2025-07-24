//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>

int main()
{
    // Declarations of the Red, Green, Blue values of the input color
    int r, g, b;

    // Prompt for input color values
    printf("Enter the Red, Green and Blue values of the input color (Range: 0 to 255):\n");
    scanf("%d %d %d", &r, &g, &b);

    //Calculations for converting RGB to Hexadecimal
    int hex1 = r/16;
    int hex2 = r%16;
    int hex3 = g/16;
    int hex4 = g%16;
    int hex5 = b/16;
    int hex6 = b%16;

    //Prints the output color in Hexadecimal Code
    printf("The output color in Hexadecimal code is: #%X%X%X%X%X%X\n", hex1, hex2, hex3, hex4, hex5, hex6);

    return 0;   //End of program
}