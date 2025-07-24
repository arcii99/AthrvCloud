//FormAI DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int choice;

    printf("*** Temperature Converter ***\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * (5.0/9.0);
        printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
    } else if(choice == 2) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * (9.0 / 5.0)) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    
    return 0;
}