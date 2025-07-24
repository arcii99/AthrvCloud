//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

int main() {

    // Welcome message
    printf("Hi there! I am the C Temperature Converter.\n");
    printf("I can help you convert from Celsius to Fahrenheit and vice versa.\n");
    printf("So, let's get started!\n\n");

    // Input values
    float celsius_input;
    float fahrenheit_input;
    printf("Please enter a temperature in Celsius: ");
    scanf("%f", &celsius_input);
    printf("\nPlease enter a temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit_input);

    // Conversion from Celsius to Fahrenheit
    float fahrenheit_output = (celsius_input * 9/5) + 32;
    printf("\n%.2f°C is %.2f°F.\n", celsius_input, fahrenheit_output);

    // Conversion from Fahrenheit to Celsius
    float celsius_output = (fahrenheit_input - 32) * 5/9;
    printf("\n%.2f°F is %.2f°C.\n", fahrenheit_input, celsius_output);

    // Farewell message
    printf("\nThank you for using the C Temperature Converter!\n");
    printf("Have a nice day!\n");

    return 0;
}