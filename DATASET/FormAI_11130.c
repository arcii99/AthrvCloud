//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

int main() {
    char choice;
    float input, output;
    printf("Welcome to Temperature Converter!\n");
    do {
        printf("Enter c for Celsius to Fahrenheit or f for Fahrenheit to Celsius: ");
        scanf(" %c", &choice);
        if (choice != 'c' && choice != 'f') {
            printf("Invalid input, please try again.\n");
            continue;
        }
        printf("Enter temperature: ");
        scanf("%f", &input);

        if (choice == 'c') {
            output = (input * 9 / 5) + 32;
            printf("%.2fC = %.2fF\n", input, output);
        } else {
            output = (input - 32) * 5 / 9;
            printf("%.2fF = %.2fC\n", input, output);
        }

        printf("Convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using Temperature Converter!\n");
    return 0;
}