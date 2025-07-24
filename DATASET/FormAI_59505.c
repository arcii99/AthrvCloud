//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float celToFah(float celsius)
{
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahToCel(float fahrenheit)
{
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main()
{
    int choice;
    float temperature;
    printf("Welcome to the futuristic temperature converter\n");
    printf("Please select your choice:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", temperature, celToFah(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", temperature, fahToCel(temperature));
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}