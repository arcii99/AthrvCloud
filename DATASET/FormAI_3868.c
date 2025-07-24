//FormAI DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (5.0/9.0) * (fahrenheit - 32);
    return celsius;
}

float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0/5.0) + 32;
    return fahrenheit; 
}

int main() {
    int choice;
    float temperature, converted_temperature;
    
    printf("Enter 1 for Fahrenheit to Celsius Conversion\n");
    printf("Enter 2 for Celsius to Fahrenheit Conversion\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted_temperature = fahrenheit_to_celsius(temperature);
        printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", temperature, converted_temperature);
    } else if (choice == 2) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        converted_temperature = celsius_to_fahrenheit(temperature);
        printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", temperature, converted_temperature);
    } else {
        printf("Invalid choice. Please enter either 1 or 2.\n");
    }
    
    return 0;
}