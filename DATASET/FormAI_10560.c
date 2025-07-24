//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main () {
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;

    printf("\nIn Cyberpunk world, the temperature is never what it seems!\n");
    printf("Converting Celsius to Fahrenheit and Kelvin: \n");
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);

    float deviation = rand() % 5 + 1; // Random deviation of 1-5 degrees
    printf("\nBut in this dystopian world, the temperature is hacked and altered constantly!\n");
    if(rand() % 2 == 0) { // Randomly choose to increase or decrease temperature
        fahrenheit += deviation;
        kelvin += deviation;
        printf("Temperature has increased by %.2f degrees.\n", deviation);
    } else {
        fahrenheit -= deviation;
        kelvin -= deviation;
        printf("Temperature has decreased by %.2f degrees.\n", deviation);
    }

    printf("\nNew temperature after hacking it: \n");
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);

    return 0;
}