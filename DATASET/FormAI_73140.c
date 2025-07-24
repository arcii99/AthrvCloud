//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert Hex code to RGB value
int hexToDec(char *hex)
{
    int num = (int)strtol(hex, NULL, 16);
    return num;
}

//function to calculate RGB components
void getRGB(int red, int green, int blue)
{
    printf("The RGB values are %d, %d, %d\n", red, green, blue);
}

int main()
{
    int red, green, blue;
    char hex[7];
    
    printf("Enter a Hex code: ");
    scanf("%s", hex);
    
    //convert Hex code to RGB components
    red = hexToDec(strncpy(hex, hex+0, 2));
    green = hexToDec(strncpy(hex, hex+2, 2));
    blue = hexToDec(strncpy(hex, hex+4, 2));
    
    //print RGB values
    getRGB(red, green, blue);
    
    return 0;
}