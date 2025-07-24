//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>

/* Function prototypes */
float convertCelsiusToFahrenheit(float celsius);
float convertFahrenheitToCelsius(float fahrenheit);
float convertMilesToKilometers(float miles);
float convertKilometersToMiles(float kilometers);

int main() {
    int option;
    float value, result;
    printf("Select an option: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    scanf("%d", &option);

    /* Switch statement to perform the selected conversion */
    switch(option) {
        case 1: /* Celsius to Fahrenheit */
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = convertCelsiusToFahrenheit(value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;
        case 2: /* Fahrenheit to Celsius */
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = convertFahrenheitToCelsius(value);
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;
        case 3: /* Miles to Kilometers */
            printf("Enter the distance in miles: ");
            scanf("%f", &value);
            result = convertMilesToKilometers(value);
            printf("%.2f miles = %.2f kilometers\n", value, result);
            break;
        case 4: /* Kilometers to Miles */
            printf("Enter the distance in kilometers: ");
            scanf("%f", &value);
            result = convertKilometersToMiles(value);
            printf("%.2f kilometers = %.2f miles\n", value, result);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}

/* Function to convert Celsius to Fahrenheit */
float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32.0;
}

/* Function to convert Fahrenheit to Celsius */
float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

/* Function to convert Miles to Kilometers */
float convertMilesToKilometers(float miles) {
    return miles * 1.60934;
}

/* Function to convert Kilometers to Miles */
float convertKilometersToMiles(float kilometers) {
    return kilometers / 1.60934;
}