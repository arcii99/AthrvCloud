//FormAI DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include<stdio.h>

//Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

//Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius){
    return celsius + 273.15;
}

int main(){
    float celsius = 0;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("Temperature in Fahrenheit: %.2f\n", celsiusToFahrenheit(celsius));
    printf("Temperature in Kelvin: %.2f", celsiusToKelvin(celsius));
    return 0;
}