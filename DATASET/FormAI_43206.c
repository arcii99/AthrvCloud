//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>

//Function to convert RGB color code to HEX color code
void RGBtoHEX(int red, int green, int blue)
{
    char hex[7]; //to store the converted HEX color code
    sprintf(hex, "#%02X%02X%02X", red, green, blue); //using sprintf function to convert the RGB code to HEX code
    printf("The HEX color code is: %s\n", hex);
}

//Function to convert HEX color code to RGB color code
void HEXtoRGB(char hex[])
{
    int red, green, blue;
    sscanf(hex, "#%02X%02X%02X", &red, &green, &blue); //using sscanf function to convert the HEX code to RGB code
    printf("The RGB color code is: %d,%d,%d\n", red, green, blue);
}

int main()
{
    int choice, red, green, blue;
    char hex[7];

    printf("Welcome to Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the RGB color code (separated by spaces): ");
        scanf("%d %d %d", &red, &green, &blue);
        RGBtoHEX(red, green, blue);
        break;
    case 2:
        printf("Enter the HEX color code (without # symbol): ");
        scanf("%s", hex);
        HEXtoRGB(hex);
        break;  
    default:
        printf("Invalid choice");
    }

    return 0;
}