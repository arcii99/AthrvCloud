//FormAI DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include <stdio.h>

int main() {
    int choice;
    float temperature, convertedTemp;

    printf("Temperature Converter\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if ( choice == 1 ) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemp = ( temperature * 1.8 ) + 32;
        printf("%.2f°C is equal to %.2f°F", temperature, convertedTemp);
    } else if ( choice == 2 ) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemp = ( temperature - 32 ) / 1.8;
        printf("%.2f°F is equal to %.2f°C", temperature, convertedTemp);
    } else {
        printf("Invalid option selected");
    }

    return 0;
}