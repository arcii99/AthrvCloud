//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {

    float celsius, fahrenheit;
    int choice;
    
    printf("Welcome to the post-apocalyptic Temperature Converter\n");
    printf("Please choose an option below:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
    }
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
    }
    else {
        printf("Invalid input\n");
    }
    return 0;
}