//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>

int main() {
    float tempF, tempC;
    int choice;

    printf("Welcome to the Cyberpunk Temperature Converter\n");
    printf("**********************************************\n");

    do {
        printf("\nEnter your choice:\n");
        printf("1. Fahrenheit to Celsius conversion\n");
        printf("2. Celsius to Fahrenheit conversion\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &tempF);
                tempC = (tempF - 32) * 5 / 9;
                printf("\nThe temperature in Celsius is: %.2f", tempC);
                break;

            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &tempC);
                tempF = (tempC * 9 / 5) + 32;
                printf("\nThe temperature in Fahrenheit is: %.2f", tempF);
                break;

            case 3:
                printf("\nExiting the program...");
                break;

            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 3);

    printf("\nThank you for using Cyberpunk Temperature Converter!");
    return 0;
}