//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Celsius to Fahrenheit converter!\n");
    printf("Please enter a temperature in Celsius: ");
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
    printf("Would you like to try again? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    while (choice == 'y') {
        printf("Please enter a temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
        printf("Would you like to try again? (y/n) ");
        scanf(" %c", &choice);
    }
    printf("Thanks for using the converter! Have a nice day!\n");
    return 0;
}