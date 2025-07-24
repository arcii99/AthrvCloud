//FormAI DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

int convertToFahrenheit(int temperature) {
    return (temperature * 9/5) + 32;
}

int convertToKelvin(int temperature) {
    return temperature + 273.15;
}

int main() {
    int temperature = 0;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature in Celsius: ");
    scanf("%d", &temperature);
    printf("\n");

    printf("What would you like to convert it to?\n");
    printf("Enter 'F' for Fahrenheit or 'K' for Kelvin: ");
    scanf(" %c", &choice);
    printf("\n");

    switch(choice) {
        case 'F':
            printf("%d Celsius is %d Fahrenheit.\n", temperature, convertToFahrenheit(temperature));
            break;
        case 'K':
            printf("%d Celsius is %d Kelvin.\n", temperature, convertToKelvin(temperature));
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}