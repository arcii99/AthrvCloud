//FormAI DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double input, output;
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n");
    printf("4. Convert Miles to Kilometers\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = (input * 9 / 5) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", input, output);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = (input - 32) * 5 / 9;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", input, output);
            break;

        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &input);
            output = input * 0.621371;
            printf("%.2lf Kilometers is equal to %.2lf Miles.\n", input, output);
            break;

        case 4:
            printf("Enter distance in Miles: ");
            scanf("%lf", &input);
            output = input * 1.60934;
            printf("%.2lf Miles is equal to %.2lf Kilometers.\n", input, output);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}