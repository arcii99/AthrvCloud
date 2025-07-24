//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>

int main() {
    // declaring variables
    int red, green, blue, hex;

    // taking input from user
    printf("Enter the RGB Color Values: \n");
    printf("Red Value (0 - 255): ");
    scanf("%d", &red);
    printf("Green Value (0 - 255): ");
    scanf("%d", &green);
    printf("Blue Value (0 - 255): ");
    scanf("%d", &blue);

    // converting RGB to hexadecimal
    hex = (red << 16) | (green << 8) | blue;

    // displaying the converted hexadecimal value
    printf("The Hexadecimal Color Code is: #%06x\n", hex);

    return 0;
}