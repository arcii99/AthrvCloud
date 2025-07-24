//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperature = 0;
    int count = 0;
    float total_temperature = 0;
    float average_temperature = 0;
    const int MAX_READINGS = 10;

    printf("Welcome to the Temperature Monitor Program\n\n");
    printf("This program will take temperature readings and calculate the average temperature.\n");

    while(count < MAX_READINGS) {
        printf("\nPlease enter a temperature reading: ");
        scanf("%f", &temperature);

        if(temperature < -100 || temperature > 100) {
            printf("Invalid temperature reading. Temperature must be between -100 and 100 degrees Celsius.\n");
            continue;
        }

        total_temperature += temperature;

        count++;

        if(count == MAX_READINGS) {
            average_temperature = total_temperature / MAX_READINGS;

            printf("\n\nAverage Temperature: %.2f degrees Celsius\n\n", average_temperature);
        }
    }

    printf("Thank you for using the Temperature Monitor Program.\n");

    return 0;
}