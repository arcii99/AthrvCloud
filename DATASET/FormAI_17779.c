//FormAI DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>

int main() {

    // Declare variables to hold temperature values
    float celsius, fahrenheit;
    int choice;

    // Display menu to user
    printf("Select an option below:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if(choice == 1) {

        // Prompt user to enter temperature in Celsius
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        // Convert Celsius to Fahrenheit
        fahrenheit = (celsius * 9/5) + 32;

        // Display result to user
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n",celsius,fahrenheit);
    }

    else if(choice == 2) {

        // Prompt user to enter temperature in Fahrenheit
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        // Convert Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * 5/9;

        // Display result to user
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n",fahrenheit,celsius);
    }

    else {
        // Display error message to user if invalid option is selected
        printf("Invalid option selected\n");
    }
    return 0;
}