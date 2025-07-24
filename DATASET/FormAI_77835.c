//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>

double convertToFahrenheit(double celsius) {
    if (celsius == 0.0) {
        return 32.0;
    } else {
        return (1.8 * convertToFahrenheit(celsius - 1.0)) + 32.0;
    }
}

int main() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = convertToFahrenheit(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}