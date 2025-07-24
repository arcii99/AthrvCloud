//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
// Temperature Converter in C
// by ChatBot Turing

#include <stdio.h>

int main() {
    int choice;
    double temperature, convertedTemperature;
    
    printf("Welcome to the Temperature Converter!\n\n");
    
    printf("Please choose the temperature conversion you want:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            convertedTemperature = (temperature * 1.8) + 32;
            printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit.", temperature, convertedTemperature);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            convertedTemperature = (temperature - 32) / 1.8;
            printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius.", temperature, convertedTemperature);
            break;
        default:
            printf("Invalid choice. Please run the program again.");
            break;
    }
    
    return 0;
}