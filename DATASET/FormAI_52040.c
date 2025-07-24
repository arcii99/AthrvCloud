//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celsius, fahrenheit;

    printf("Welcome to the temperature converter!\n");
    printf("Please enter the temperature in Celsius:\n");
    scanf("%f", &celsius);

    /* Conversion formula */
    fahrenheit = (celsius * 9 / 5) + 32;

    /* Output the result */
    printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", celsius, fahrenheit);

    /* Add some creativity */
    if (celsius < 0)
    {
        printf("\nBrr, that's freezing cold!");
    }
    else if (celsius >= 0 && celsius <= 10)
    {
        printf("\nIt's chilly outside.");
    }
    else if (celsius > 10 && celsius <= 20)
    {
        printf("\nPerfect weather for a stroll.");
    }
    else if (celsius > 20 && celsius <= 30)
    {
        printf("\nSummer is here!");
    }
    else
    {
        printf("\nIt's hot as hell!");
    }

    return 0;
}