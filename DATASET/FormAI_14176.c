//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

float convertToFahrenheit(float celsius);
float convertToKelvin(float celsius);
void userInput();

int main() {
    userInput();
    return 0;
}

float convertToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

float convertToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

void userInput() {
    float celsius;
    char choice;

    printf("Enter Temperature in Celsius: ");
    scanf("%f", &celsius);
    getchar();

    printf("\nChoose Conversion Unit\n");
    printf("1. Fahrenheit (F)\n");
    printf("2. Kelvin (K)\n");
    printf("Enter Choice (F/K): ");
    scanf("%c", &choice);

    if(choice == 'F' || choice == 'f') {
        float fahrenheit = convertToFahrenheit(celsius);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.", celsius, fahrenheit);
    }
    else if(choice == 'K' || choice == 'k') {
        float kelvin = convertToKelvin(celsius);
        printf("%.2f Celsius is equal to %.2f Kelvin.", celsius, kelvin);
    }
    else {
        printf("Invalid input. Please try again.");
        userInput();
    }
}