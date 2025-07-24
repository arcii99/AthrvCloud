//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    do {
        printf("Enter 1 to convert Celsius to Fahrenheit\n");
        printf("Enter 2 to convert Fahrenheit to Celsius\n");
        printf("Enter 0 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}