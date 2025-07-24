//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define process struct
typedef struct {
    int pid;
    char name[50];
    char status[20];
    float memory_usage;
} Process;

// Function to get random number for memory usage
float get_random_number() {
    float r = (float)rand()/(float)RAND_MAX;
    return r*100;
}

int main() {
    // Define array to hold processes
    Process processes[10];

    // Initialize array with random values
    for (int i = 0; i < 10; i++) {
        processes[i].pid = i+1;
        sprintf(processes[i].name, "process%d", i+1);
        sprintf(processes[i].status, "running");
        processes[i].memory_usage = get_random_number();
    }

    // Print out header
    printf("PID\tName\t\t\tStatus\t\tMemory Usage\n");

    // Loop through processes and print out information in a surreal style
    for (int i = 0; i < 10; i++) {
        printf("%d\t", processes[i].pid);
        printf("%s\t\t", processes[i].name);
        if (strcmp(processes[i].status, "running") == 0) {
            printf("is currently doing the tango\t");
        } else if (strcmp(processes[i].status, "stopped") == 0) {
            printf("is taking a nap\t\t\t");
        } else if (strcmp(processes[i].status, "zombie") == 0) {
            printf("is feeling a little undead\t");
        } else {
            printf("is in a deep existential crisis\t");
        }
        if (processes[i].memory_usage > 50) {
            printf("and is absorbing memories like a black hole\t%.2f%%\n", processes[i].memory_usage);
        } else {
            printf("and seems to have a poor memory\t%.2f%%\n", processes[i].memory_usage);
        }
    }

    return 0;
}