//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

// Function to convert from Celsius degrees to Fahrenheit degrees
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert from Fahrenheit degrees to Celsius degrees
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert from kilometers per hour to miles per hour
float kmhToMph(float kmh) {
    return kmh / 1.609;
}

// Function to convert from miles per hour to kilometers per hour
float mphToKmh(float mph) {
    return mph * 1.609;
}

int main() {
    int option;
    float value;
    
    printf("Welcome to the Shape-Shifting Unit Converter!\n\n");
    
    do {
        printf("Please select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers per hour to Miles per hour\n");
        printf("4. Miles per hour to Kilometers per hour\n");
        printf("5. Exit\n");
        
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Please enter the value in Celsius: ");
                scanf("%f", &value);
                
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", value, celsiusToFahrenheit(value));
                
                break;
            case 2:
                printf("Please enter the value in Fahrenheit: ");
                scanf("%f", &value);
                
                printf("%.2f Fahrenheit = %.2f Celsius\n\n", value, fahrenheitToCelsius(value));
                
                break;
            case 3:
                printf("Please enter the value in Kilometers per hour: ");
                scanf("%f", &value);
                
                printf("%.2f Kilometers per hour = %.2f Miles per hour\n\n", value, kmhToMph(value));
                
                break;
            case 4:
                printf("Please enter the value in Miles per hour: ");
                scanf("%f", &value);
                
                printf("%.2f Miles per hour = %.2f Kilometers per hour\n\n", value, mphToKmh(value));
                
                break;
            case 5:
                printf("Thank you for using the Shape-Shifting Unit Converter!\n");
                
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                
                break;
        }
    } while (option != 5);
    
    return 0;
}