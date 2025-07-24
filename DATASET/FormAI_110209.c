//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include<stdio.h>

int main() {
    printf("Welcome to the Celsius to Fahrenheit Temperature Converter!\n");
    printf("Please enter a Celsius temperature:\n");
    float celsius;
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n\n", celsius, fahrenheit);

    printf("Do you want to convert Fahrenheit back to Celsius? (Y/N)\n");
    char response;
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        printf("Please enter a Fahrenheit temperature:\n");
        float fahrenheit_input;
        scanf("%f", &fahrenheit_input);
        
        float celsius_output = (fahrenheit_input - 32) * 5 / 9;

        printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", fahrenheit_input, celsius_output);
    } else {
        printf("Thank you for using our temperature converter!\n");
    }

    return 0;
}