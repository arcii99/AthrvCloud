//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>

// Recursive function to convert temperature from Celsius to Fahrenheit
double convertTemp(double celsius)
{
    // Base case
    if (celsius == 0)
        return 32;
    
    // Recursive case
    else
        return (1.8 * convertTemp(celsius - 1)) + 32;
}

int main()
{
    double c;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &c);

    printf("%.2lf degrees Celsius = %.2lf degrees Fahrenheit\n", c, convertTemp(c));

    return 0;
}