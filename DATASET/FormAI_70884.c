//FormAI DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

/* This program converts distance from miles to kilometers and vice versa. It also converts temperature 
from Celsius to Fahrenheit and vice versa. */

int main() {
    
    double miles, kilometers, celsius, fahr;

    printf("Welcome to the unit converter.\n");

    printf("\nDistance converter - Please enter the distance in miles: ");
    scanf("%lf", &miles);

    // Conversion from miles to kilometers
    kilometers = miles * 1.60934;

    printf("%.2lf miles is equal to %.2lf kilometers.\n", miles, kilometers);

    printf("\nTemperature converter - Please enter the temperature in Celsius: ");
    scanf("%lf", &celsius);

    // Conversion from Celsius to Fahrenheit
    fahr = (celsius * 9/5) + 32;

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahr);

    printf("\nBack to Distance converter - Please enter the distance in kilometers: ");
    scanf("%lf", &kilometers);

    // Conversion from kilometers to miles
    miles = kilometers / 1.60934;

    printf("%.2lf kilometers is equal to %.2lf miles.\n", kilometers, miles);

    printf("\nBack to Temperature converter - Please enter the temperature in Fahrenheit: ");
    scanf("%lf", &fahr);

    // Conversion from Fahrenheit to Celsius
    celsius = (fahr - 32) * 5/9;

    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahr, celsius);

    printf("\nThank you for using the unit converter.\n");

    return 0;
}