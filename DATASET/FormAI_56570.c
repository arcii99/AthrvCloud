//FormAI DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>

int main() {
    char choice; // letter for type of temperature that user wants to convert
    double temp, convertedTemp; // temp will be taken from user, convertedTemp will be the result after conversion

    printf("Welcome to the Temperature Converter program!\n");

    while (1) { // loop allows user to convert multiple times without having to run program again
        printf("\nPlease choose the type of temperature to convert: \n");
        printf("C) Celsius to Fahrenheit\n");
        printf("F) Fahrenheit to Celsius\n");
        printf("Q) Quit Temperature Converter\n");

        fflush(stdin); // clear input buffer
        scanf("%c", &choice);

        switch (choice) {
            case 'C':
            case 'c':
                printf("\nPlease enter the temperature in Celsius: ");
                scanf("%lf", &temp);
                convertedTemp = (temp * (9.0/5.0)) + 32; // conversion formula
                printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit.\n", temp, convertedTemp);
                break;
            case 'F':
            case 'f':
                printf("\nPlease enter the temperature in Fahrenheit: ");
                scanf("%lf", &temp);
                convertedTemp = (temp - 32) * (5.0/9.0); // conversion formula
                printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius.\n", temp, convertedTemp);
                break;
            case 'Q':
            case 'q':
                printf("\nThank you for using the Temperature Converter program.\n");
                // end program
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}