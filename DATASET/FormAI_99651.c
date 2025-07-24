//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include<stdio.h>

/*This program converts temperature from Celsius to Fahrenheit and vice versa*/

//Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float temp) {
    float fahr = (temp * 9/5) + 32;
    return fahr;
}

//Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float temp) {
    float celsius = (temp - 32) * 5/9;
    return celsius;
}

int main() {
    int choice;
    float temperature;

    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("\nInvalid choice\n");
    }

    return 0;
}