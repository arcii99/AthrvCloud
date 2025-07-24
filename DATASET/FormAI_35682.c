//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Welcome to the cheerful temperature converter!\n");
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

    printf("Feeling chilly? Let me convert your Celsius temperature to Fahrenheit!\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsius * 9 / 5 + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    printf("Do you want to convert temperatures again? (Y/N)\n");
    char answer;
    scanf(" %c", &answer);

    while(answer == 'Y' || answer == 'y') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5 / 9;

        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

        printf("Feeling chilly? Let me convert your Celsius temperature to Fahrenheit!\n");
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = celsius * 9 / 5 + 32;

        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

        printf("Do you want to convert temperatures again? (Y/N)\n");
        scanf(" %c", &answer);
    }

    printf("Thank you for using the cheerful temperature converter!\n");

    return 0;
}