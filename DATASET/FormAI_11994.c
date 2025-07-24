//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("------ Fahrenheit to Celsius Converter ------\n");
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);

    printf("\n------ Celsius to Fahrenheit Converter ------\n");
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}