//FormAI DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

float celsiusToFahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius){
    return celsius + 273.15;
}

int main(){
    float celsius = 0.0;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("Temperature in Fahrenheit: %.2f\n", celsiusToFahrenheit(celsius));
    printf("Temperature in Kelvin: %.2f\n", celsiusToKelvin(celsius));
    return 0;
}