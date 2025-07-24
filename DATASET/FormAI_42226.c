//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("**** Welcome to the unique CPU Scheduling Algorithm Simulation! ****\n");
    printf("We are about to simulate the Elefantastic Scheduling Algorithm.\n");
    printf("This algorithm is known to be one of the most efficient scheduling algorithms out there!\n\n");

    printf(">>> The simulation will now start.\n");
    printf("We will simulate a system with 10 processes with random arrival times and execution times.\n");
    printf("The system will run for a single CPU time slice of 10 seconds.\n");
    printf("Hold on tight, this is going to be Elefuntastic!\n\n");

    srand(time(NULL));
    int AT[10], ET[10], remainingBT[10], WT[10], TAT[10];
    float total_WT = 0, total_TAT = 0;

    // Generate random arrival times and execution times for each process
    for(int i=0; i<10; i++)
    {
        AT[i] = rand() % 20;
        ET[i] = rand() % 20 + 1;
        remainingBT[i] = ET[i];
        WT[i] = 0;
        TAT[i] = 0;
    }

    printf("Process\tArrival Time\tExecution Time\n");
    for(int i=0; i<10; i++)
    {
        printf("P%d\t%d\t\t%d\n", i+1, AT[i], ET[i]);
    }

    printf("\n>>> Starting CPU scheduling simulation with Elefantastic Algorithm...\n");

    int time = 0, completed_processes = 0;
    printf("\nTime %d: CPU is idle.\n", time);

    while(completed_processes != 10)
    {
        int shortest_BT = -1 , shortest_index = -1;

        for(int i=0; i<10; i++)
        {
            if(AT[i] <= time && remainingBT[i] > 0)
            {
                if(shortest_BT == -1 || remainingBT[i] < shortest_BT)
                {
                    shortest_BT = remainingBT[i];
                    shortest_index = i;
                }
            }
        }

        if(shortest_index != -1)
        {
            remainingBT[shortest_index]--;

            printf("Time %d: CPU executing P%d. Remaining Burst Time = %d\n", time+1, shortest_index+1, remainingBT[shortest_index]);

            if(remainingBT[shortest_index] == 0)
            {
                completed_processes++;
                TAT[shortest_index] = time + 1 - AT[shortest_index];
                WT[shortest_index] = TAT[shortest_index] - ET[shortest_index];
                total_WT += WT[shortest_index];
                total_TAT += TAT[shortest_index];
                printf("Time %d: P%d has completed execution. Turnaround Time = %d, Waiting Time = %d.\n", time+1, shortest_index+1, TAT[shortest_index], WT[shortest_index]);
            }
        }
        else
        {
            printf("Time %d: CPU is idle.\n", time+1);
        }

        time++;

        if(time % 10 == 0 && time != 0)
        {
            printf("Time %d: CPU time slice of 10 seconds is over. Context switch will occur.\n", time);
        }
    }

    float avg_WT = total_WT / 10, avg_TAT = total_TAT / 10;
    printf("\n>>> CPU scheduling simulation with Elefantastic Algorithm is over!\n");
    printf("Average Waiting Time = %.2f\n", avg_WT);
    printf("Average Turnaround Time = %.2f\n", avg_TAT);

    return 0;
}