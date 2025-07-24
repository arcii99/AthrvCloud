//FormAI DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    // Display menu
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Convert Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f C = %.2f F", celsius, fahrenheit);
            break;
        
        case 2:
            // Convert Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f F = %.2f C", fahrenheit, celsius);
            break;
        
        default:
            printf("Invalid choice");
    }

    return 0;
}