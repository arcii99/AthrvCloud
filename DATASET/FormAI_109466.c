//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);

    printf("Would you like to convert Fahrenheit to Celsius? (y/n)\n");
    char response = getchar();
    if (response == 'y' || response == 'Y') {
        float fahrenheit_input, celsius_output;
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit_input);
        celsius_output = (fahrenheit_input - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f°C\n", celsius_output);
    } else {
        printf("Thank you for using our temperature converter!\n");
    }

    return 0;
}