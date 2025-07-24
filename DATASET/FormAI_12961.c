//FormAI DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>

/* Function to convert Celsius to Fahrenheit */
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

/* Function to convert Celsius to Kelvin */
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

/* Main function */
int main() {
    float celsius;
    int choice;
    
    printf("Enter the temperature in Celsius: \n");
    scanf("%f", &celsius);
    
    printf("Select the conversion type: \n");
    printf("1. Celsius to Fahrenheit \n");
    printf("2. Celsius to Kelvin \n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("%.2f C = %.2f F", celsius, celsiusToFahrenheit(celsius));
            break;
        case 2:
            printf("%.2f C = %.2f K", celsius, celsiusToKelvin(celsius));
            break;
        default:
            printf("Invalid choice");
    }
    
    return 0;
}