//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include<stdio.h>

float convertToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float convertToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius; //The temperature in Celsius
    int choice; //The user's choice of conversion type
    
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    
    printf("\nChoose the type of conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            float fahrenheit = convertToFahrenheit(celsius);
            printf("\n%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
            break;
        }
        
        case 2: {
            float kelvin = convertToKelvin(celsius);
            printf("\n%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
            break;
        }
        
        default: {
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}