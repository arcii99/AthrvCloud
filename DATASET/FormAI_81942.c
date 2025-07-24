//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Introduction
    printf("Welcome to the Temperature Converter!\n");
    printf("This program will convert temperatures from Celsius to Fahrenheit and vice versa.\n");

    // Variables
    char temp_type[10];
    float temp, result;

    // User Input
    printf("Enter the temperature type you want to convert (Celsius/Fahrenheit): ");
    scanf("%s", temp_type);
    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    // Conversion
    if(strcmp(temp_type, "Celsius") == 0) 
    {
        result = (temp * 9/5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temp, result);
    }
    else if(strcmp(temp_type, "Fahrenheit") == 0) 
    {
        result = (temp - 32) * 5/9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temp, result);
    }
    else 
    {
        printf("Invalid temperature type entered.\n");
        return 1;
    }

    // Conclusion
    printf("Thank you for using the Temperature Converter!\n");
    return 0;
}