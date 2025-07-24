//FormAI DATASET v1.0 Category: System boot optimizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_WAIT_TIME 1
#define MAX_WAIT_TIME 5

int main()
{
    srand(time(0)); // seed random number generator

    printf("Welcome to C System boot optimizer!!\n\n");

    int num_of_processes;
    printf("Enter number of processes running during startup: ");
    scanf("%d", &num_of_processes);

    int starting_time[num_of_processes];
    int ending_time[num_of_processes];

    printf("\nEnter the starting time and ending time for each process: \n\n");

    for (int i = 0; i < num_of_processes; i++)
    {
        printf("Process %d start time: ", i + 1);
        scanf("%d", &starting_time[i]);

        printf("Process %d end time: ", i + 1);
        scanf("%d", &ending_time[i]);
    }

    bool optimized = false;

    while (!optimized)
    {
        optimized = true; // assume the system is optimized, until proven otherwise
        printf("\nAnalyzing system boot time...\n\n");

        for (int i = 0; i < num_of_processes - 1; i++)
        {
            if (starting_time[i+1] < ending_time[i]) // if next process starts before current process ends
            {
                printf("Process %d (%d - %d) and process %d (%d - %d) overlap.\n", 
                i + 1, starting_time[i], ending_time[i], i + 2, starting_time[i+1], ending_time[i+1]);

                printf("Optimizing...\n\n");

                // delay the start of next process
                int wait_time = rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME + 1) + MIN_WAIT_TIME;
                printf("Waiting %d seconds before starting process %d...\n", wait_time, i + 2);
                starting_time[i+1] += wait_time;

                printf("New start time for process %d: %d\n\n", i + 2, starting_time[i+1]);

                optimized = false;
            }
        }

        if (optimized)
        {
            printf("Total system boot time is %d seconds.\n", ending_time[num_of_processes-1]);
        }
    }

    return 0;
}