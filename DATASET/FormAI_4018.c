//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include<stdio.h>

int main()
{
    float celsius, fahrenheit; 
    int choice;
    printf("Temperature Converter Menu\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: 
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f°C is equal to %.2f°F\n", celsius, fahrenheit);
            break;
        case 2: 
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f°F is equal to %.2f°C\n", fahrenheit, celsius);
            break;
        default:
            printf("Invalid Choice!\n");
    }
    return 0;
}