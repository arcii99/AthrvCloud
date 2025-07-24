//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hexVal[6];
    char colorCode[10];

    printf("Enter a Color Code in Hexadecimal (format: XXXXXX): ");
    scanf("%s", hexVal);

    if (strlen(hexVal) != 6) // Check if the hex value is in valid format
    {
        printf("Invalid Input! Please enter a 6-digit hexadecimal value!\n");
        printf("Example: FFFFFF\n");
        return 0;
    }

    char* ptr;
    long int decimalVal = strtol(hexVal, &ptr, 16); // Converting hexadecimal to decimal

    int red = (decimalVal & 0xff0000) >> 16; // Extracting Red color code
    int green = (decimalVal & 0x00ff00) >> 8; // Extracting Green color code
    int blue = (decimalVal & 0x0000ff); // Extracting Blue color code

    sprintf(colorCode, "rgb(%d, %d, %d)", red, green, blue); // Creating RGB color code

    printf("The RGB color code for #%s is %s\n", hexVal, colorCode);

    return 0;
}