//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // To generate random numbers

    int temperature = 0, temp_min = 0, temp_max = 100;
    int i = 0, j = 0;

    printf("Welcome to the Temperature Monitoring System!\n\n");

    while (1) {
        printf("Temperature: %dC\n", temperature);

        if (temperature <= temp_min) {
            printf("Temperature is too low! Increasing temperature...\n");
            temperature += rand() % 10 + 1; // Increase temperature by a random number between 1 and 10
        }
        else if (temperature >= temp_max) {
            printf("Temperature is too high! Decreasing temperature...\n");
            temperature -= rand() % 10 + 1; // Decrease temperature by a random number between 1 and 10
        }
        else {
            int temp_change = rand() % 3 - 1; // Generate a random number between -1 and 1
            temperature += temp_change; // Change temperature by the random number
            if (temp_change == 0) {
                printf("Temperature is unchanged.\n");
            }
            else if (temp_change < 0) {
                printf("Temperature has decreased by %dC.\n", -temp_change);
            }
            else {
                printf("Temperature has increased by %dC.\n", temp_change);
            }
        }

        // Sleep for 1 second before updating the temperature again
        for (i = 0; i < 100000000; i++) {
            for (j = 0; j < 10; j++);
        }

        printf("\n");
    }

    return 0;
}