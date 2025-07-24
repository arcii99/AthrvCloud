//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

//function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

//function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

void printTemperature(double celsius) {
    printf("\n---------------------------\n");
    printf("Celsius: %lf °C\n", celsius);
    printf("Fahrenheit: %lf °F\n", celsiusToFahrenheit(celsius));
    printf("Kelvin: %lf K\n", celsiusToKelvin(celsius));
    printf("---------------------------\n");
}

int main() {
    char input[10];
    double celsius = 0.0;

    do {
        printf("Enter temperature in Celsius (q to quit): ");
        scanf("%s", input);

        if (input[0] == 'q') {
            break;
        }

        celsius = atof(input);
        if (celsius < -273.15) {
            printf("Error: Temperature below absolute zero.\n");
        } else {
            printTemperature(celsius);
        }
    } while (1);

    return 0;
}