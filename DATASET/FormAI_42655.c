//FormAI DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>

//Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

//Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

//Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

//Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

//Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

//Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

int main() {
    int option;
    float value;

    printf("Unit Converter Program\n");
    printf("----------------------\n");
    printf(" 1. Celsius to Fahrenheit\n");
    printf(" 2. Fahrenheit to Celsius\n");
    printf(" 3. Celsius to Kelvin\n");
    printf(" 4. Kelvin to Celsius\n");
    printf(" 5. Fahrenheit to Kelvin\n");
    printf(" 6. Kelvin to Fahrenheit\n");
    printf(" 7. Exit Program\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        if(option == 7) {
            printf("\nExiting Program...\n");
            break;
        }

        printf("Enter the value: ");
        scanf("%f", &value);

        switch(option) {
            case 1:
                printf("%0.3f Celsius = %0.3f Fahrenheit\n", value, celsiusToFahrenheit(value));
                break;
            case 2:
                printf("%0.3f Fahrenheit = %0.3f Celsius\n", value, fahrenheitToCelsius(value));
                break;
            case 3:
                printf("%0.3f Celsius = %0.3f Kelvin\n", value, celsiusToKelvin(value));
                break;
            case 4:
                printf("%0.3f Kelvin = %0.3f Celsius\n", value, kelvinToCelsius(value));
                break;
            case 5:
                printf("%0.3f Fahrenheit = %0.3f Kelvin\n", value, fahrenheitToKelvin(value));
                break;
            case 6:
                printf("%0.3f Kelvin = %0.3f Fahrenheit\n", value, kelvinToFahrenheit(value));
                break;
            default:
                printf("Invalid option, please try again\n");
        }
    }

    return 0;
}