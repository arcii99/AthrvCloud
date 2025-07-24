//FormAI DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>

/* A Color Code Converter Program in C language */

int main() {

    int colorCode;    // Variable to store the color code input by the user
    char* colorName;  // Pointer to store the color name
    
    // Prompting user to enter the color code
    printf("Enter the color code (1-7): ");
    scanf("%d", &colorCode);

    // Assigning color name based on the color code entered by the user
    switch(colorCode) {
        case 1:
            colorName = "Red";
            break;
        case 2:
            colorName = "Orange";
            break;
        case 3:
            colorName = "Yellow";
            break;
        case 4:
            colorName = "Green";
            break;
        case 5:
            colorName = "Blue";
            break;
        case 6:
            colorName = "Indigo";
            break;
        case 7:
            colorName = "Violet";
            break;
        default:
            printf("Invalid color code!\n");
            return 0;
    }
    
    // Displaying the color name corresponding to the entered color code
    printf("The color corresponding to the code %d is %s\n", colorCode, colorName);

    return 0;
}