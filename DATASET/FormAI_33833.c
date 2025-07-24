//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperature;
    char scale;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter the current temperature in Celsius (C) or Fahrenheit (F): ");
    scanf("%f%c", &temperature, &scale);

    if (scale == 'C' || scale == 'c') {
        if (temperature <= -273.15) {
            printf("Cannot input a temperature below absolute zero!");
        } else {
            printf("%.2f Celsius is equal to %.2f Fahrenheit and %.2f Kelvin\n", temperature, ((temperature * 9/5) + 32), (temperature + 273.15));
        }
    } else if (scale == 'F' || scale == 'f') {
        if (temperature <= -459.67) {
            printf("Cannot input a temperature below absolute zero!");
        } else {
            printf("%.2f Fahrenheit is equal to %.2f Celsius and %.2f Kelvin\n", temperature, ((temperature - 32) * 5/9), (((temperature - 32) * 5/9) + 273.15));
        }
    } else {
        printf("Invalid scale entered. Please try again.\n");
    }

    printf("\nThank you for using the Temperature Monitor! Stay cool (or warm) out there!");
    return 0;
}