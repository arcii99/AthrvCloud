//FormAI DATASET v1.0 Category: System boot optimizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOOT_TIME 30 //in seconds
#define MAX_PROCESSES 10

int main() {
    int processes[MAX_PROCESSES], bootTime = 0, i, j;
    srand(time(0)); //seed random number generator with current time

    //generate random number of processes with random execution times
    for(i=0; i<MAX_PROCESSES; i++) {
        processes[i] = rand() % 10 + 1; //execution time from 1 to 10 seconds
        printf("Process %d: %ds\n", i+1, processes[i]);
    }

    //simulate system boot process, executing processes in order of shortest execution time first
    printf("\nSystem booting...\n");
    while(bootTime < BOOT_TIME) {
        int shortestProcessIndex = -1, shortestProcessTime = 11;
        for(i=0; i<MAX_PROCESSES; i++) {
            if(processes[i] != 0 && processes[i] < shortestProcessTime) {
                shortestProcessIndex = i;
                shortestProcessTime = processes[i];
            }
        }
        if(shortestProcessIndex != -1) {
            printf("Executing process %d...\n", shortestProcessIndex+1);
            processes[shortestProcessIndex] = 0; //mark process as completed
            bootTime += shortestProcessTime;
        }
        else {
            printf("No more processes to execute\n");
            break;
        }
    }

    if(bootTime >= BOOT_TIME)
        printf("\nSystem booted successfully in %d seconds!\n", bootTime);
    else
        printf("\nSystem failed to boot within %d seconds\n", BOOT_TIME);

    return 0;
}