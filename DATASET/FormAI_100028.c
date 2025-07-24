//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    float celsius, fahrenheit;
    int choice;
    printf("Choose an option:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: // Celsius to Fahrenheit conversion
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.2f°C = %.2f°F", celsius, fahrenheit);
            break;

        case 2: // Fahrenheit to Celsius conversion
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f°F = %.2f°C", fahrenheit, celsius);
            break;

        default:
            printf("Invalid option");
            break;
    }
    return 0;
}