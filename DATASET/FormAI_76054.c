//FormAI DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the C Temperature Converter program!\n");
    
    float celsius, fahrenheit;
    int choice;
    printf("Select one of the following options: \n");
    printf("1. Celsius to Fahrenheit \n");
    printf("2. Fahrenheit to Celsius \n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f°C is equivalent to %.2f°F\n", celsius, fahrenheit);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f°F is equivalent to %.2f°C\n", fahrenheit, celsius);
            break;
        
        default:
            printf("Invalid option selected. Please try again.");
            break;
    }
    
    printf("Thank you for using the C Temperature Converter program!\n");
    
    return 0;
}