//FormAI DATASET v1.0 Category: Unit converter ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

//Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}

//Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

int main(){

    int choice;
    float temperature, result;

    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                result = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius = %.2f Fahrenheit", temperature, result);
                break;
        
        case 2: printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                result = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit = %.2f Celsius", temperature, result);
                break;
        
        default: printf("Invalid choice");
    }
    
    return 0;
}