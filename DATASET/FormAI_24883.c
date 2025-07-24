//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>
#include <stdbool.h>

int main() {
    int choice;
    double temperature;
    bool quit = false;

    while (!quit) {
        printf("Menu:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", temperature, temperature * 1.8 + 32);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n\n", temperature, (temperature - 32) / 1.8);
                break;
            case 3:
                printf("Quitting program...\n");
                quit = true;
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    }
    return 0;
}