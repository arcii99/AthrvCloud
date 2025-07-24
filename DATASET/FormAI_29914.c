//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main() {
    float temp;
    int choice;

    printf("Enter temperature: ");
    scanf("%f", &temp);

    printf("Choose conversion type:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // checking user choice
    switch(choice) {
        case 1: printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit", temp, celsiusToFahrenheit(temp));
                break;
        case 2: printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius", temp, fahrenheitToCelsius(temp));
                break;
        default: printf("Invalid choice! Please choose either 1 or 2.");
    }

    return 0;
}