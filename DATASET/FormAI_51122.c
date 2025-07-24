//FormAI DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, upper_range, lower_range;
    srand(time(0)); //seeding the random number generator with the current time

    printf("\nEnter the lower range of the temperature to be monitored: ");
    scanf("%d", &lower_range);
    printf("\nEnter the upper range of the temperature to be monitored: ");
    scanf("%d", &upper_range);

    if (lower_range > upper_range)
    {
        printf("\nInvalid temperature range! Lower range cannot be greater than upper range.");
        return 0;
    }

    printf("\nTemperature Monitor\n");
    printf("-------------------\n");
    printf("Lower Range: %d\n", lower_range);
    printf("Upper Range: %d\n\n", upper_range);

    while (1)
    {
        temperature = (rand() % (upper_range - lower_range + 1)) + lower_range; //generating a random temperature within the given range

        printf("Current Temperature: %d C\n", temperature);

        if (temperature < lower_range)
            printf("!!! WARNING !!! The temperature is below the lower range.\n\n");

        else if (temperature > upper_range)
            printf("!!! WARNING !!! The temperature is above the upper range.\n\n");

        else
            printf("The temperature is within the specified range.\n\n");

        sleep(3); //pausing the loop for 3 seconds before the next iteration
    }

    return 0;
}