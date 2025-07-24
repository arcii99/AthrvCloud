//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    double inputTemp, outputTemp, celsiusToFahrenheit, fahrenheitToCelsius;
    int choice;

    printf("Hi there! I am an Alan Turing-style C Temperature Converter. Please choose an option to convert between Celsius and Fahrenheit: \n");
    printf("1) Celsius to Fahrenheit\n");
    printf("2) Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose Celsius to Fahrenheit. Please enter a temperature in Celsius: \n");
            scanf("%lf", &inputTemp);

            celsiusToFahrenheit = (inputTemp * 9/5) + 32;
            printf("%.2lf degrees Celsius equals to %.2lf degrees Fahrenheit. Thanks for using this program!\n", inputTemp, celsiusToFahrenheit);
            break;
        
        case 2:
            printf("You chose Fahrenheit to Celsius. Please enter a temperature in Fahrenheit: \n");
            scanf("%lf", &inputTemp);

            fahrenheitToCelsius = (inputTemp - 32) * 5/9;
            printf("%.2lf degrees Fahrenheit equals to %.2lf degrees Celsius. Thanks for using this program!\n", inputTemp, fahrenheitToCelsius);
            break;
        
        default:
            printf("Invalid option. Program exiting now. Thanks for trying it out.\n");
    }

    return 0;
}