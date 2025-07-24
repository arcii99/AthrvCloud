//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float convertCelsiusToFahrenheit(float celsius){
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// function to convert Celsius to Kelvin
float convertCelsiusToKelvin(float celsius){
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main(){
    float celsius, fahrenheit, kelvin;

    // ask user for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // convert Celsius to Fahrenheit
    fahrenheit = convertCelsiusToFahrenheit(celsius);

    // convert Celsius to Kelvin
    kelvin = convertCelsiusToKelvin(celsius);

    // print the results
    printf("\n%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
    printf("\n%.2f Celsius = %.2f Kelvin", celsius, kelvin);

    return 0;
}