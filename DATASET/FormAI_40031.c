//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int choice;

    printf("Welcome to Temperature Converter!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = celsius * 9 / 5 + 32;
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
                break;
            case 3:
                printf("Thank you for using Temperature Converter!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}