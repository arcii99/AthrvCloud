//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hex[7], red[3], green[3], blue[3];
    printf("Enter a hexadecimal color code (like #FFFFFF): ");
    scanf("%s", hex);
    
    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("Invalid color code. Please enter a hexadecimal color code (like #FFFFFF).");
        return 1;
    }
    
    strncpy(red, hex+1, 2);
    strncpy(green, hex+3, 2);
    strncpy(blue, hex+5, 2);
    red[2] = green[2] = blue[2] = '\0';
    
    int redVal = strtol(red, NULL, 16);
    int greenVal = strtol(green, NULL, 16);
    int blueVal = strtol(blue, NULL, 16);

    printf("The RGB color code for %s is: (%d, %d, %d)", hex, redVal, greenVal, blueVal);
    return 0;
}