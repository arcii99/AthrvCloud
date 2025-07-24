//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

//function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

//function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

    float kelvin = celsius_to_kelvin(celsius);
    printf("%.2f Celsius is equal to %.2f Kelvin", celsius, kelvin);

    return 0;
}