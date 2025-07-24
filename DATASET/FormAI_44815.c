//FormAI DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0

// Function to generate a random temperature between 0 and 100
double gen_random_temp()
{
    double temp = (double)rand() / (RAND_MAX + 1.0) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
    return temp;
}

int main()
{
    int i, j;
    double current_temp, temp_sum;
    double temp_array[10][5];

    // Generate temperature readings for each hour of the day for the past 10 days
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            current_temp = gen_random_temp();
            temp_array[i][j] = current_temp;
            temp_sum += current_temp;
        }
    }

    // Calculate average temperature for the past 10 days
    double avg_temp = temp_sum / 50.0;

    // Display temperature readings and average temperature
    printf("Temperature Readings\n");
    printf("-----------------------------\n");

    for(i = 0; i < 10; i++)
    {
        printf("Day %d: ", i+1);
        for(j = 0; j < 5; j++)
        {
            printf("%0.2f ", temp_array[i][j]);
        }
        printf("\n");
    }

    printf("-----------------------------\n");
    printf("Average Temp for the past 10 days: %0.2f\n", avg_temp);

    return 0;
}