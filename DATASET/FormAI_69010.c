//FormAI DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Welcome to the Celsius to Fahrenheit converter!\n");
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}