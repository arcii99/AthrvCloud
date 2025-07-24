//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

float convertCtoF(float celsius) {
    return (celsius * 1.8) + 32;
}

float convertCtoK(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius, fahrenheit, kelvin;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = convertCtoF(celsius);
    kelvin = convertCtoK(celsius);
    
    printf("\nTemperature in Fahrenheit: %.2f", fahrenheit);
    printf("\nTemperature in Kelvin: %.2f", kelvin);
    
    return 0;
}