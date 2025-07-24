//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float current_temperature, min_temperature = 20.0, max_temperature = 30.0, sum_temperature = 0.0, avg_temperature;
    int count = 0;

    printf("Welcome to the temperature monitor!\n");

    while (1)
    {
        srand((unsigned)time(NULL));
        current_temperature = (float)(rand() % 101) / 10.0; // Generate a random temperature between 0 and 10 degrees Celsius

        printf("Current temperature: %.1fC\n", current_temperature);

        if (current_temperature < min_temperature)
        {
            min_temperature = current_temperature;
            printf("New minimum temperature: %.1fC\n", min_temperature);
        }

        if (current_temperature > max_temperature)
        {
            max_temperature = current_temperature;
            printf("New maximum temperature: %.1fC\n", max_temperature);
        }

        sum_temperature += current_temperature;
        count++;

        avg_temperature = sum_temperature / count;
        printf("Average temperature: %.1fC\n", avg_temperature);

        printf("Press any key to continue or enter Q to quit: ");

        char input = getchar();
        while (getchar() != '\n');

        if (input == 'Q' || input == 'q')
        {
            printf("Exiting temperature monitor...\n");
            break;
        }
    }

    return 0;
}