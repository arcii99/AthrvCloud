//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("===============================================================\n");
    printf("\t\t\tTemperature Converter\n");
    printf("===============================================================\n\n");

    float temp;
    char choice;
    printf("Please choose the unit of temperature you want to enter: \n");
    printf("F: Fahrenheit \nC: Celsius \nK: Kelvin \n");
    scanf("%c", &choice);

    switch(choice) {
        case 'F':
        case 'f':
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.2f Fahrenheit is equal to %.2f Celsius and %.2f Kelvin.\n", temp, (temp-32)*5/9, (temp-32)*5/9 + 273.15);
            break;

        case 'C':
        case 'c':
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.2f Celsius is equal to %.2f Fahrenheit and %.2f Kelvin.\n", temp, (temp*9/5)+32, temp + 273.15);
            break;

        case 'K':
        case 'k':
            printf("\nEnter the temperature in Kelvin: ");
            scanf("%f", &temp);
            printf("%.2f Kelvin is equal to %.2f Fahrenheit and %.2f Celsius.\n", temp, (temp-273.15)*9/5+32, temp - 273.15);
            break;

        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}