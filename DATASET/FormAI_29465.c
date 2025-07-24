//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include<stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("Enter 1 to convert Celsius to Fahrenheit.\n");
    printf("Enter 2 to convert Fahrenheit to Celsius.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
            break;

        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            break;
    }

    return 0;
}