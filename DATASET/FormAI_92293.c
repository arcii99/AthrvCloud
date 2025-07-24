//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

int main()
{
    char choice;
    float temp, result;

    printf("This is a temperature conversion program\n");
    printf("Please select the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case '1':
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temp);
            result = (temp * 9/5) + 32;
            printf("%.2fC = %.2fF\n", temp, result);
            break;
        case '2':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temp);
            result = (temp - 32) * 5/9;
            printf("%.2fF = %.2fC\n", temp, result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}