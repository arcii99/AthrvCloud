//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tempCelsius, tempFahrenheit, choice;
    printf("Enter 1 to convert Celsius to Fahrenheit or 2 to convert Fahrenheit to Celsius: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter temperature in Celsius: ");
        scanf("%d", &tempCelsius);
        tempFahrenheit = (tempCelsius * 9/5) + 32;
        printf("\n%d degree Celsius is equal to %d degree Fahrenheit.", tempCelsius, tempFahrenheit);
    } else if (choice == 2) {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%d", &tempFahrenheit);
        tempCelsius = (tempFahrenheit - 32) * 5/9;
        printf("\n%d degree Fahrenheit is equal to %d degree Celsius.", tempFahrenheit, tempCelsius);
    } else {
        printf("\nInvalid choice. Please enter 1 or 2.");
        exit(0);
    }

    return 0;
}