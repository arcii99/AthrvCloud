//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

/* Function to convert from Celsius to Fahrenheit */
float c_to_f(float celsius)
{
    return ((celsius * 9) / 5) + 32;
}

/* Function to convert from Fahrenheit to Celsius */
float f_to_c(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

int main()
{
    int choice;
    float input, output;
    
    printf("Welcome to the Unit Converter\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = c_to_f(input);
            printf("%f Celsius = %f Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = f_to_c(input);
            printf("%f Fahrenheit = %f Celsius\n", input, output);
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}