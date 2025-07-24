//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;
    
    printf("Enter conversion choice:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.2f degrees Celsius = %.2f degrees Fahrenheit", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit = %.2f degrees Celsius", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice.");
    }
    
    return 0;
}