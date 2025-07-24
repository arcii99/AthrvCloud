//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    char choice;

    printf("Welcome to the C Color Code Converter! \n");
    printf("Please enter the RGB values as integers between 0 and 255. \n");

    printf("Red: ");
    scanf("%d", &red);

    printf("Green: ");
    scanf("%d", &green);

    printf("Blue: ");
    scanf("%d", &blue);

    printf("Do you want to convert to hexadecimal(H) or decimal(D)? Enter H or D: ");
    scanf(" %c", &choice);

    if (choice == 'D' || choice == 'd') {
        printf("Red: %d\n", red);
        printf("Green: %d\n", green);
        printf("Blue: %d\n", blue);
    } else if (choice == 'H' || choice == 'h') {
        printf("Hexadecimal Value: #%02X%02X%02X\n", red, green, blue);
    } else {
        printf("Invalid input. Please enter 'H' or 'D'. \n");
        return 0;
    }

    printf("\nThank you for using the C Color Code Converter! \n");
    return 0;
}