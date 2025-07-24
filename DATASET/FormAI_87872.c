//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

float feetToMeters(float feet) {
    return feet * 0.3048;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    int choice;
    float input;

    printf("Enter 1 to convert feet to meters.\n");
    printf("Enter 2 to convert Fahrenheit to Celsius.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            printf("%.2f feet is %.2f meters", input, feetToMeters(input));
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            printf("%.2f F is %.2f C", input, fahrenheitToCelsius(input));
            break;

        default:
            printf("Invalid choice.");
            break;
    }

    return 0;
}