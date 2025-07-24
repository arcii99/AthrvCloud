//FormAI DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;
    printf("Welcome to the Temperature Converter!\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice. Please enter either 1 or 2.");
    }
    return 0;
}