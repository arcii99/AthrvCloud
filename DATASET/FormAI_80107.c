//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include<stdio.h>

//function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius){
    float fahrenheit;
    fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

//function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit){
    float celsius;
    celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main(){
    int choice, temp;
    float value, convertedValue;
    printf("****Unit converter****\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\nEnter the value of temperature: ");
    scanf("%f", &value);
    switch(choice){
        case 1:
            convertedValue = celsiusToFahrenheit(value);
            printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit.\n", value, convertedValue);
            break;
        case 2:
            convertedValue = fahrenheitToCelsius(value);
            printf("\n%f degrees Fahrenheit is equal to %f degrees Celsius.\n", value, convertedValue);
            break;
        default:
            printf("\nInvalid choice entered.\n");
    }
    return 0;
}