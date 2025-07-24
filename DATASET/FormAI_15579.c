//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    float celsius, fahrenheit;
    char decision = 'y';

    printf("Greetings, survivor! Welcome to the temperature converter.\n");

    while(decision == 'y') {
        printf("Please enter a temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9 / 5) + 32;

        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

        printf("Would you like to convert another temperature? (y/n) ");
        scanf(" %c", &decision);
    }

    printf("Stay safe, survivor. Goodbye.\n");

    return 0;
}