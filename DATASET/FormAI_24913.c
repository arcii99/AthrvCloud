//FormAI DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>

int main() {
    float c, f;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &c);
            f = (c * 9 / 5) + 32;
            printf("%.2f Celsius is equivalent to %.2f Fahrenheit.", c, f);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &f);
            c = (f - 32) * 5 / 9;
            printf("%.2f Fahrenheit is equivalent to %.2f Celsius.", f, c);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.");
    }

    return 0;
}