//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

void welcome();
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);
void goodbye();

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    welcome();

    do {
        printf("\nEnter Celsius temperature to convert: ");
        scanf("%lf", &celsius);

        fahrenheit = celsiusToFahrenheit(celsius);
        kelvin = celsiusToKelvin(celsius);

        printf("\n%lf Celsius is equivalent to:\n", celsius);
        printf("%lf Fahrenheit\n", fahrenheit);
        printf("%lf Kelvin\n", kelvin);

        printf("\nDo you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    goodbye();

    return 0;
}

void welcome() {
    printf("Welcome to the Celsius Temperature Converter!\n\n");
}

double celsiusToFahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

void goodbye() {
    printf("\nThank you for using the Celsius Temperature Converter. Goodbye!\n");
}