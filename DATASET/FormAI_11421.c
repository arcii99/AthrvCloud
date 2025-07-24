//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;
    
    printf("Select an option to convert temperature:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2fC = %.2fF\n", celsius, fahrenheit);
            break;
            
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2fF = %.2fC\n", fahrenheit, celsius);
            break;
            
        default:
            printf("Invalid option selected.");
    }
    
    return 0;
}