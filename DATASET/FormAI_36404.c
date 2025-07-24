//FormAI DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float convertCtoF(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float convertFtoC(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    int choice;
    float temperature;

    printf("Choose the number for the conversion you want to make: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2fC is equal to %.2fF", temperature, convertCtoF(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2fF is equal to %.2fC", temperature, convertFtoC(temperature));
            break;
        default:
            printf("Invalid choice, please choose 1 or 2");
            break;
    }

    return 0;
}