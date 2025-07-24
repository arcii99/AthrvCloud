//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
/* Welcome to the hilarious Temperature Converter program! */
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    // Introduction
    printf("Welcome to the Temperature Converter program!\n\n");
    printf("What would you like to convert today?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    // Choice Input
    printf("\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {  // Celsius to Fahrenheit
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.\n", celsius, fahrenheit);
    }
    else if (choice == 2) {  // Fahrenheit to Celsius
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%.1f degrees Fahrenheit is equal to %.1f degrees Celsius.\n", fahrenheit, celsius);
    }
    else {  // Invalid choice
        printf("\nInvalid choice! Please choose either 1 or 2.\n");
    }

    // Funny message to end the program
    printf("\nThanks for using the Temperature Converter program! Remember, always keep your cool and stay hot!\n");
    return 0;
}