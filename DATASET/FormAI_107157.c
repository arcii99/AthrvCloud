//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    printf("\nWelcome to the Airport Baggage Handling Simulation\n");

    int i, j;   
    int queues[4][3] = {0};  // initializing baggage queues
    int num_of_bags;
    bool bag_processed = false;
    int min_time, max_time;
    int total_bags_processed = 0;
    srand(time(NULL));

    while(total_bags_processed < 100)
    {
        // Randomly generate number of bags for each passenger
        num_of_bags = rand() % 6;

        // Find the shortest queue
        int shortest_queue;
        int min_length = 100;
        for (i = 0; i < 4; i++)
        {
            int queue_length = 0;
            for (j = 0; j < 3; j++)
            {
                if (queues[i][j] > 0)
                {
                    queue_length++;
                }
            }

            if (queue_length < min_length)
            {
                min_length = queue_length;
                shortest_queue = i;
            }
        }

        // Add passenger to the shortest queue
        for (i = 0; i < 3; i++)
        {
            if (queues[shortest_queue][i] == 0)
            {
                queues[shortest_queue][i] = num_of_bags;
                break;
            }    
        }

        // Process first bag in each queue every minute
        for (i = 0; i < 4; i++)
        {
            if (queues[i][0] > 0)
            {
                bag_processed = true;

                printf("\nProcessing baggage in Queue %d: Bag of %d kg\n", i, queues[i][0]);

                // Set baggage processing time based on weight of bag
                if (queues[i][0] <= 3)
                {
                    min_time = 1;
                    max_time = 2;
                }
                else if (queues[i][0] > 3 && queues[i][0] <= 6)
                {
                    min_time = 2;
                    max_time = 3;
                }
                else
                {
                    min_time = 3;
                    max_time = 4;
                }

                // Remove processed bag from queue
                for (j = 0; j < 2; j++)
                {
                    queues[i][j] = queues[i][j+1];
                }
                queues[i][2] = 0;

                // Random delay to simulate baggage processing time
                int processing_time = rand() % (max_time - min_time + 1) + min_time;
                for (j = 0; j < processing_time; j++)
                {
                    printf(".");
                    sleep(1); // 1 second delay
                }

                printf("\nBag processed in %d minutes\n", processing_time);

                total_bags_processed++;
            }
        }

        // If no bags were processed, simulate 1 minute delay
        if (!bag_processed)
        {
            printf("\nNo bags processed this minute\n");
            sleep(1); // 1 second delay
        }

        bag_processed = false;

        // Print the status of each queue
        printf("\nCurrent queue status:\n");
        for (i = 0; i < 4; i++)
        {
            printf("Queue %d: ", i);
            for (j = 0; j < 3; j++)
            {
                printf("%d ", queues[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nAll bags have been processed successfully\n");

    return 0;
}