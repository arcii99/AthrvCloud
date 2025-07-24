//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random temperatures
float generate_temperature()
{
    float temp = 0;
    int sign = rand() % 2; // 0 or 1

    // Generate a random float between 0 and 100
    temp = (float)(rand() % 100);

    // Add a random decimal to the temperature
    temp += (float)(rand() % 10) / 10;

    if (sign == 0) {
        temp *= -1; // Make the temperature negative
    }

    return temp;
}

int main()
{
    int num_days = 7;
    float temperatures[num_days];
    float avg_temp = 0;
    float total_temp = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate temperatures for each day of the week
    for (int i = 0; i < num_days; i++) {
        temperatures[i] = generate_temperature();
        total_temp += temperatures[i];
    }

    // Calculate the average temperature
    avg_temp = total_temp / num_days;

    // Print the temperatures and the average temperature
    printf("Weekly Temperatures:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_days; i++) {
        printf("Day %d: %.1f\n", i+1, temperatures[i]);
    }
    printf("--------------------\n");
    printf("Average Temperature: %.1f\n", avg_temp);

    return 0;
}