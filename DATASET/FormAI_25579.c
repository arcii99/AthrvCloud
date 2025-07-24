//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to the unique C Unit Converter!\n\n");

    bool running = true;

    while (running) {
        int choice;
        float value, result;

        printf("Please select an option:\n");
        printf("1 - Celsius to Fahrenheit\n");
        printf("2 - Fahrenheit to Celsius\n\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Celsius value: ");
            scanf("%f", &value);
            result = (value * 1.8) + 32;
            printf("%f Celsius is equal to %f Fahrenheit\n\n", value, result);
        } else if (choice == 2) {
            printf("Enter Fahrenheit value: ");
            scanf("%f", &value);
            result = (value - 32) / 1.8;
            printf("%f Fahrenheit is equal to %f Celsius\n\n", value, result);
        } else {
            printf("Invalid choice, please try again.\n\n");
        }

        char continueInput;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueInput);

        if (continueInput == 'n' || continueInput == 'N') {
            running = false;
        }

        printf("\n");
    }

    return 0;
}