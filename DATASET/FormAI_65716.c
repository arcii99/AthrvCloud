//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float celsius, fahrenheit, kelvin;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    //convert Celsius to Fahrenheit
    fahrenheit = (celsius * 1.8) + 32;
    
    //convert Celsius to Kelvin
    kelvin = celsius + 273.15;
    
    printf("\nCelsius Temperature: %0.2f C", celsius);
    printf("\nFahrenheit Temperature: %0.2f F", fahrenheit);
    printf("\nKelvin Temperature: %0.2f K", kelvin);
    
    return 0;
}