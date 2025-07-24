//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;
    int i;

    printf("Welcome to the C Temperature Monitor!\n");
    printf("This program will randomly generate temperature readings for the last 24 hours.\n\n");

    srand(time(NULL)); // Initialize random seed

    for (i = 0; i < 24; i++)
    {
        temperature = (float)(rand() % 15) + 25; // Generate temperature in the range of 25-39 degrees Celsius
        printf("Temperature reading %d: %.2fC\n", i+1, temperature);
    }

    printf("\nThank you for using the C Temperature Monitor!");

    return 0;
}