//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {

    float celsius;
    float fahrenheit;

    printf("Welcome to the Celsius to Fahrenheit converter\n\n");
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("The temperature in Fahrenheit is: %0.2f", fahrenheit);

    return 0;
}