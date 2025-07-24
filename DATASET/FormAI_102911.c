//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include<stdio.h>

int main()
{
    int choice;
    float temp, converted;
    printf("Temperature converter:\n");
    printf("1.Celsius to Fahrenheit\n");
    printf("2.Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: // Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            converted = (temp * 9/5) + 32; // Conversion formula
            printf("%.2f Celsius = %.2f Fahrenheit\n", temp, converted);
            break;
        
        case 2: // Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            converted = (temp - 32) * 5/9; // Conversion formula
            printf("%.2f Fahrenheit = %.2f Celsius\n", temp, converted);
            break;
        
        default:
            printf("Invalid choice\n");
    }
    return 0;
}