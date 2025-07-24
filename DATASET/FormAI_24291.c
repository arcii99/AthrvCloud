//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

int main(){
    int choice;
    float value;

    printf("Welcome to Unit Converter\n\n");
    printf("Choose the conversion you'd like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the value in Celsius: ");
            scanf("%f", &value);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.", value, celsiusToFahrenheit(value));
            break;
        case 2:
            printf("Enter the value in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.", value, fahrenheitToCelsius(value));
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}