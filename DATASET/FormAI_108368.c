//FormAI DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main(){
    float celsius;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Temperature in Fahrenheit: %.2f\n", celsiusToFahrenheit(celsius));
    printf("Temperature in Kelvin: %.2f\n", celsiusToKelvin(celsius));

    return 0;
}

float celsiusToFahrenheit(float celsius){
    return ((celsius*9)/5) + 32;
}

float celsiusToKelvin(float celsius){
    return celsius + 273.15;
}