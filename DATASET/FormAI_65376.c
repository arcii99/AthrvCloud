//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

int main() {
    int choice;
    float temp_celsius, temp_fahrenheit;
    
    printf("Welcome to the Celsius to Fahrenheit and Fahrenheit to Celsius converter!\n");
    printf("Please choose which conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp_celsius);
        temp_fahrenheit = (temp_celsius * 9 / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temp_celsius, temp_fahrenheit);
    }
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp_fahrenheit);
        temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temp_fahrenheit, temp_celsius);
    }
    else {
        printf("Invalid choice entered. Please try again.\n");
    }
    
    return 0;
}