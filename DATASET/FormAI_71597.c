//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main() {
    float temp_celsius, temp_fahrenheit;
    int option;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 1 to convert Celsius to Fahrenheit.\n");
    printf("Enter 2 to convert Fahrenheit to Celsius.\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter the temperature in degrees Celsius: ");
        scanf("%f", &temp_celsius);
        temp_fahrenheit = (temp_celsius * 9 / 5) + 32;
        printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit.", temp_celsius, temp_fahrenheit);
    } else if (option == 2) {
        printf("Enter the temperature in degrees Fahrenheit: ");
        scanf("%f", &temp_fahrenheit);
        temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
        printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius.", temp_fahrenheit, temp_celsius);
    } else {
        printf("Invalid option selected.");
    }

    return 0;
}