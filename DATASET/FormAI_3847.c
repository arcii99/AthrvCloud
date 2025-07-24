//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hello there! Let's convert some temperatures!\n");

    // Ask user for input
    printf("Please enter the temperature in Celsius: ");
    float celsius;
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    float fahrenheit = (celsius * 9 / 5) + 32;

    // Display the result
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

    // Confirm with the user if they want to convert another temperature
    printf("Would you like to convert another temperature? Type 'y' for yes and 'n' for no: ");
    char answer;
    scanf(" %c", &answer);
    while(answer != 'n') {
        // Ask for the temperature to convert
        printf("Please enter the temperature in Celsius: ");
        scanf("%f", &celsius);

        // Convert Celsius to Fahrenheit
        fahrenheit = (celsius * 9 / 5) + 32;

        // Display the result
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

        // Confirm with the user if they want to convert another temperature
        printf("Would you like to convert another temperature? Type 'y' for yes and 'n' for no: ");
        scanf(" %c", &answer);
    }

    // Farewell message
    printf("Thank you for using our temperature converter. Have a great day!");

    return 0;
}