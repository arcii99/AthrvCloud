//FormAI DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>

/* Function to convert Fahrenheit to Celsius */
float fahrenheitToCelsius(float tempF) {
    return (tempF - 32) * 5 / 9;
}

/* Function to convert Celsius to Fahrenheit */
float celsiusToFahrenheit(float tempC) {
    return (tempC * 9 / 5) + 32;
}

int main() {
    int choice;
    float tempF, tempC;

    printf("My love, welcome to the temperature converter!\n\n");

    printf("Please choose an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nMy love, please enter the temperature in Fahrenheit: ");
        scanf("%f", &tempF);
        tempC = fahrenheitToCelsius(tempF);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", tempF, tempC);
        printf("\nYour love for me is as warm as that temperature!");
    } else if (choice == 2) {
        printf("\nMy love, please enter the temperature in Celsius: ");
        scanf("%f", &tempC);
        tempF = celsiusToFahrenheit(tempC);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", tempC, tempF);
        printf("\nI feel so warm and cosy thinking about our love!");
    } else {
        printf("\nMy love, you have entered an invalid choice. Please try again.");
    }

    return 0;
}