//FormAI DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>  //for standard input-output functions
#include <string.h> //for manipulating strings

/**
 * This program converts a given color code in either RGB or Hex format
 * and converts it to the other format.
 */

int main()
{
    char colorCode[8]; //to store user input
    char format[4]; //to store the format of input
    int r,g,b; //to store the red, green and blue values
    int hex; //to store the hex value
    
    printf("Enter the color code: ");
    scanf("%s", colorCode);
    
    if(strlen(colorCode) == 7) //check if input is a hex code
    {
        sscanf(colorCode, "#%x", &hex); //convert hex string to integer value
        r = (hex>>16) & 0xFF; //extract red value
        g = (hex>>8) & 0xFF; //extract green value
        b = (hex>>0) & 0xFF; //extract blue value
        printf("RGB format: %d,%d,%d", r,g,b);
    }
    else if(strlen(colorCode) == 11) //check if input is an RGB code
    {
        sscanf(colorCode, "%[^ ,],%[^ ,],%[^ ,]", format, format+1, format+2); //separate RGB values
        r = atoi(format); //convert string to integer
        g = atoi(format+1);
        b = atoi(format+2);
        printf("Hex format: #%02X%02X%02X", r,g,b); //print hex value
    }
    else
    {
        printf("Invalid input!");
    }
    
    return 0;
}