//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>

int main() {

    float temp_c, temp_f, temp_k;
    char choice;

    printf("Welcome to the temperature converter.\n");

    do {
        printf("\nEnter the temperature in Celsius: ");
        scanf("%f", &temp_c);

        // Convert Celsius to Fahrenheit
        temp_f = (temp_c * (9.0 / 5.0)) + 32.0;

        // Convert Celsius to Kelvin
        temp_k = temp_c + 273.15;

        printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit and %.2f Kelvin.\n", temp_c, temp_f, temp_k);

        printf("\nWould you like to convert another temperature? (Y/N) ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using the temperature converter.\n");

    return 0;
}