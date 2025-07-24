//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

int main() {
    float input;
    int choice;

    printf("Please enter the value to be converted: ");
    scanf("%f", &input);

    printf("\nPlease choose the unit type to convert from:\n");
    printf("\t1. Celsius\n");
    printf("\t2. Fahrenheit\n");
    printf("\t3. Kelvin\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);

    printf("\n");

    switch (choice) {
        case 1:
            printf("%.2f Celsius equals:\n", input);
            printf("%.2f Fahrenheit\n", input * 9/5 + 32);
            printf("%.2f Kelvin\n", input + 273.15);
            break;
        case 2:
            printf("%.2f Fahrenheit equals:\n", input);
            printf("%.2f Celsius\n", (input - 32) * 5/9);
            printf("%.2f Kelvin\n", (input + 459.67) * 5/9);
            break;
        case 3:
            printf("%.2f Kelvin equals:\n", input);
            printf("%.2f Celsius\n", input - 273.15);
            printf("%.2f Fahrenheit\n", input * 9/5 - 459.67);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}