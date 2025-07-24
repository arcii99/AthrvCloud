//FormAI DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

void generate_random_temperature(int *temperature)
{
    *temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

void print_temperature(int temperature)
{
    printf("Current temperature: %d\n", temperature);
}

int main()
{
    srand(time(NULL)); // seed random function with current time

    int temperature;
    generate_random_temperature(&temperature);
    print_temperature(temperature);

    char input;
    while (1)
    {
        printf("Press 'n' to generate a new temperature or 'q' to quit: ");
        scanf(" %c", &input);

        if (input == 'n')
        {
            generate_random_temperature(&temperature);
            print_temperature(temperature);
        }
        else if (input == 'q')
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid input!\n");
        }
    }

    return 0;
}