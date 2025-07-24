//FormAI DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tempC, tempF;

    printf("Welcome to the Celsius to Fahrenheit temperature converter!\n\n");
    printf("Please enter a temperature in Celsius: ");
    scanf("%f", &tempC);

    tempF = (tempC * 9 / 5) + 32;

    printf("\n%0.2f Celsius is equal to %0.2f Fahrenheit.\n", tempC, tempF);

    printf("\nThank you for using our temperature converter!\n");

    return 0;
}