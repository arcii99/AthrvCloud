//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int current_temp = 70;          // starting temperature
    int target_temp;                // user input
    srand(time(NULL));              // seed random number generator

    printf("Welcome to the Weather Simulation Program!\n");

    while (1)
    {
        printf("Please enter your desired temperature (Enter -1 to quit): ");
        scanf("%d", &target_temp);

        if (target_temp == -1)      // exit loop if user enters -1
            break;

        while (current_temp != target_temp)     // loop until target temperature is reached
        {
            int change = rand() % 5 - 2;        // randomly generate temperature change in range of -2 to 2
            current_temp += change;

            if (current_temp < 0)               // set lower limit to 0
                current_temp = 0;
            else if (current_temp > 100)        // set upper limit to 100
                current_temp = 100;
            
            printf("Current temperature: %d\n", current_temp);
        }

        printf("Target temperature reached!\n\n");
    }

    printf("Thank you for using the Weather Simulation Program!\n");

    return 0;
}