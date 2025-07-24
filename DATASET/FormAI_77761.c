//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red = 0, green = 0; // traffic light status
    int cars_waiting = 0; // number of cars waiting at each traffic light
    int time_elapsed = 0; // elapsed time in seconds
    int total_cars_passed = 0; // total number of cars passed

    // Seed the random number generator with current time
    srand(time(NULL));

    // Simulate traffic flow for 1 hour (3600 seconds)
    while (time_elapsed < 3600)
    {
        // Assume two traffic lights at an intersection
        // First traffic light turns red after 30 seconds and green after 40 seconds
        // Second traffic light turns red after 50 seconds and green after 30 seconds

        // Check if first traffic light is green
        if (green > 0)
        {
            // Choose a random number of cars between 0 and 5
            int cars = rand() % 6;
            total_cars_passed += cars;
            printf("%d cars passed first traffic light (total: %d)\n", cars, total_cars_passed);
            green--;

            // Check if there are still cars waiting at the first traffic light
            if (cars_waiting > 0)
            {
                // Let the first traffic light turn yellow for 5 seconds
                printf("First traffic light turns yellow\n");
                green = -5;
            }
        }
        else
        {
            // Choose a random number of cars between 0 and 2
            int cars = rand() % 3;
            cars_waiting += cars;
            printf("%d cars arrived at first traffic light (total waiting: %d)\n", cars, cars_waiting);

            // Check if first traffic light turns red
            if (red == 0 && cars_waiting > 0)
            {
                printf("First traffic light turns red\n");
                red = 30;
            }
        }

        // Check if second traffic light is green
        if (green > 0)
        {
            // Choose a random number of cars between 0 and 3
            int cars = rand() % 4;
            total_cars_passed += cars;
            printf("%d cars passed second traffic light (total: %d)\n", cars, total_cars_passed);
            green--;

            // Check if there are still cars waiting at the second traffic light
            if (cars_waiting > 0)
            {
                // Let the second traffic light turn yellow for 5 seconds
                printf("Second traffic light turns yellow\n");
                green = -5;
            }
        }
        else
        {
            // Choose a random number of cars between 0 and 4
            int cars = rand() % 5;
            cars_waiting += cars;
            printf("%d cars arrived at second traffic light (total waiting: %d)\n", cars, cars_waiting);

            // Check if second traffic light turns red
            if (red == 0 && cars_waiting > 0)
            {
                printf("Second traffic light turns red\n");
                red = 50;
            }
        }

        // Update traffic light status and time elapsed
        red--;
        green++;
        time_elapsed++;
    }

    return 0;
}