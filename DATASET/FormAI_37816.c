//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
/* The Case of the Mysterious Temperature Converter */

#include <stdio.h>

int main()
{
    /* The game is afoot */
    printf("Greetings, my dear companions. It seems we have stumbled upon a case of utmost importance - the mystery of temperature conversion.\n\n");

    /* Obtain the temperature from the user */
    double fahrenheit, celsius;
    printf("Please input the temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    /* Convert the temperature */
    celsius = (fahrenheit - 32) * 5 / 9;

    /* Present the findings */
    printf("\nThe temperature in Celsius is: %.2lf\n", celsius);

    /* Case closed */
    printf("\nAh, another successful case solved. Elementary, my dear Watson.\n");

    return 0;
}