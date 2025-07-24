//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {

    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit!\n", celsius, fahrenheit);

    printf("Don't you just love being able to convert temperatures effortlessly? I know I do!\n");

    printf("But wait, there's more!\n");

    printf("Would you like to convert Fahrenheit to Celsius instead? (y/n): ");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5/9;

        printf("%.2f Fahrenheit is equal to %.2f Celsius!\n", fahrenheit, celsius);

        printf("I'm so happy we can accommodate all your temperature conversion needs. \n");
    }
    else {
        printf("That's okay, we can stick to Celsius to Fahrenheit for now. \n");
    }

    printf("Thanks for using our temperature conversion program. Have a wonderful day!");

    return 0;
}