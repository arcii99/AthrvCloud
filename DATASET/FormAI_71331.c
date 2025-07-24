//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include<stdio.h>

int main()
{
    int choice, celsius, fahrenheit;
    printf("Choose an option: \n 1. Celsius to Fahrenheit\n 2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%d", &celsius);
            fahrenheit = celsius * 9/5 + 32;
            printf("Temperature in Fahrenheit is: %d°F\n", fahrenheit);
            break;
        
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%d", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("Temperature in Celsius is: %d°C\n", celsius);
            break;
        
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}