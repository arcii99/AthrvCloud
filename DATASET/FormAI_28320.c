//FormAI DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>

void main() {
    float F, C;
    int choice;

    printf("Welcome to the Celsius-Fahrenheit temperature converter\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Convert from Celsius to Fahrenheit\n");
        printf("2. Convert from Fahrenheit to Celsius\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &C);

                F = (C * 9/5) + 32;

                printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit\n", C, F);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &F);

                C = (F - 32) * 5/9;

                printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius\n", F, C);
                break;

            case 3:
                printf("\nThank you for using the temperature converter!\n");
                return;

            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }
}