//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 20

typedef struct {
    char name[20];
    int time; // time in seconds for process execution
} process;

int main() {
    srand(time(0));
    process allProcesses[MAX_PROCESSES];
    int numProcesses = rand() % MAX_PROCESSES + 1; // select random number of processes up to MAX_PROCESSES
    
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter process name and time in seconds (separated by space): ");
        scanf("%s %d", allProcesses[i].name, &allProcesses[i].time);
    }

    bool swapped = true;
    int lastUnsorted = numProcesses - 1;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < lastUnsorted; i++) {
            if (allProcesses[i].time < allProcesses[i+1].time) {
                process temp = allProcesses[i];
                allProcesses[i] = allProcesses[i+1];
                allProcesses[i+1] = temp;
                swapped = true;
            }
        }
        lastUnsorted--;
    }

    printf("\nOptimized boot sequence:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%s (%d sec)\n", allProcesses[i].name, allProcesses[i].time);
    }

    return 0;
}