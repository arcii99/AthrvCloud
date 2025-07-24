//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include<stdio.h>

int main()
{
    float fahrenheit, celsius;
    int choice;
    printf("Enter your choice: \n");
    printf("1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n");
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
            printf("Invalid choice!");
            break;
    }
    return 0;
}