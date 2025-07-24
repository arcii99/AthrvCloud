//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>

int main() {
    float Celsius, Fahrenheit;
    char ans;

    printf("Welcome to the Celsius to Fahrenheit converter!\n");
    printf("The only thing we can convert right now is the temperature!\n");
    printf("Would you like to continue? (y/n)\n");
    scanf("%c", &ans);

    if ((ans == 'y') || (ans == 'Y')) {
        printf("Perfect! Let's begin!\n");

        printf("Please input the temperature in Celsius: ");
        scanf("%f", &Celsius);

        Fahrenheit = (Celsius * 9 / 5) + 32;

        printf("The temperature in Fahrenheit is %.2f F\n", Fahrenheit);
        printf("Make sure to keep this information safe! Our converter is top secret!\n");
    } else {
        printf("Oh no! We won't be able to convert your temperature!\n");
        printf("Maybe next time!\n");
    }

    return 0;
}