//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9; 
}

// function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15; 
}

// function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15; 
}

// function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    double celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

// function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

int main() {
    int choice;
    double temperature;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("\nChoose the type of conversion:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Thank you for using the Unit Converter!\n");
            break;
        }

        printf("Enter the temperature: ");
        scanf("%lf", &temperature);

        switch (choice) {
            case 1:
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
                break;
            case 2:
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius\n", temperature, fahrenheitToCelsius(temperature));
                break;
            case 3:
                printf("%.2lf degrees Celsius is equal to %.2lf Kelvin\n", temperature, celsiusToKelvin(temperature));
                break;
            case 4:
                printf("%.2lf Kelvin is equal to %.2lf degrees Celsius\n", temperature, kelvinToCelsius(temperature));
                break;
            case 5:
                printf("%.2lf degrees Fahrenheit is equal to %.2lf Kelvin\n", temperature, fahrenheitToKelvin(temperature));
                break;
            case 6:
                printf("%.2lf Kelvin is equal to %.2lf degrees Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}