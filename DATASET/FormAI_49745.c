//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
// Welcome to the temperature converter!

#include <stdio.h>

int main() {
    printf("Hi there! I'm your friendly temperature converter!\n");
    printf("Let's change the temperature from Celsius to Fahrenheit!\n\n");

    float celsius, fahrenheit;

    printf("Please enter a temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = 1.8 * celsius + 32;

    printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit!\n", celsius, fahrenheit);

    printf("\nThat was easy! Let's do another one! This time let's convert from Fahrenheit to Celsius.\n\n");

    float fahr, cels;

    printf("Please enter a temperature in Fahrenheit: ");
    scanf("%f", &fahr);

    cels = (fahr - 32) / 1.8;

    printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius!\n", fahr, cels);

    printf("\nThanks for using the temperature converter! Have a great day!\n");

    return 0;
}