//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seed for random number generator

    // Variables for baggage handling simulation
    int num_passengers = 0;
    int total_weight = 0;
    int conveyor_capacity = 100;
    int cart_capacity = 150;
    int baggage_cart_count = 1;
    int baggage_processed = 0;
    int wait_time = 0;
    int avg_wait_time = 0;
    int total_wait_time = 0;
    int bags_per_min = 0;

    // Welcome message
    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    // Loop through each hour of the day
    for (int hour = 0; hour < 24; ++hour)
    {
        // Generate random number of passengers for this hour
        num_passengers = rand() % 1000 + 1;

        // Calculate the baggage weight for these passengers
        total_weight = num_passengers * (rand() % 50 + 1);

        // Calculate the time required to process all the baggage
        baggage_processed = 0;
        wait_time = 0;
        while (baggage_processed < total_weight)
        {
            // Check if there are any baggage carts available
            if (baggage_cart_count == 0)
            {
                ++wait_time;
                continue;
            }
            else if (wait_time > 0)
            {
                // Decrement the wait time for each baggage cart that is available
                for (int i = 0; i < baggage_cart_count; ++i)
                {
                    --wait_time;
                }
            }
            
            // Calculate the number of bags that can be loaded onto the conveyor belt
            int bags_on_conveyor = conveyor_capacity - bags_per_min;

            // If there are no bags on the conveyor, load as many as possible from the baggage cart
            if (bags_on_conveyor == 0)
            {
                // Check if there is enough space on the baggage cart to load more bags
                if (baggage_processed + cart_capacity <= total_weight)
                {
                    baggage_processed += cart_capacity;
                    --baggage_cart_count;
                }
                else
                {
                    break;
                }
            }
            else
            {
                // Load as many bags as possible onto the conveyor belt
                int bags_for_conveyor = bags_on_conveyor < cart_capacity ? bags_on_conveyor : cart_capacity;

                // Check if there is enough space on the baggage cart to load more bags
                if (baggage_processed + bags_for_conveyor <= total_weight)
                {
                    baggage_processed += bags_for_conveyor;
                    bags_per_min += bags_for_conveyor;
                }
                else
                {
                    break;
                }
            }
        }

        // Calculate the average wait time for this hour
        total_wait_time += wait_time;
        avg_wait_time = total_wait_time / (hour + 1);

        // Calculate the number of bags processed per minute for this hour
        bags_per_min = baggage_processed / 60;

        // Display the results for this hour
        printf("Hour %d:\n", hour + 1);
        printf("Number of passengers: %d\n", num_passengers);
        printf("Total baggage weight: %d kg\n", total_weight);
        printf("Bags per minute: %d\n", bags_per_min);
        printf("Average wait time: %d min\n", avg_wait_time);
        printf("\n");

        // Reset variables for the next hour
        conveyor_capacity = 100;
        cart_capacity = 150;
        baggage_cart_count = 1;
        baggage_processed = 0;
        wait_time = 0;
    }

    // Farewell message
    printf("Thank you for using the Airport Baggage Handling Simulation!\n");

    return 0;
}