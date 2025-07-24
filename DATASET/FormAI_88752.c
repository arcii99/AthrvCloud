//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() { 
    float celsius, fahrenheit; // declaring variables
    int option;
    
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n"); // prompting user for input
    printf("Enter your choice: ");
    scanf("%d", &option); // reading user input
    
    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            
            fahrenheit = (celsius * 9/5) + 32; // formula for conversion
            
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
            break;
            
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            
            celsius = (fahrenheit - 32) * 5/9; // formula for conversion
            
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
            break;
            
        default:
            printf("Invalid input");
    }
    
    return 0; // indicating successful program execution
}