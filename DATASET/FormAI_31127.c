//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_RAM_USAGE 1048576    // 1 Megabyte

typedef struct {
    int pid;
    int ram_usage;
} process;

int main() {

    int total_ram_usage = 0;
    int num_processes = 0;
    process *processes = malloc(sizeof(process) * num_processes);

    while (1) {

        // Simulate a new process being created with random RAM usage
        int new_ram_usage = rand() % 1024;   // Random value between 0 and 1023 kilobytes
        printf("New process created with RAM usage of %d kilobytes.\n", new_ram_usage);

        // Check if the new process will cause the total RAM usage to exceed the maximum
        if (total_ram_usage + new_ram_usage > MAX_RAM_USAGE) {
            printf("New process cannot be created due to lack of available memory.\n");
            // Cleanup and exit
            free(processes);
            return 1;
        }

        // Update the list of processes and total RAM usage
        num_processes++;
        processes = realloc(processes, sizeof(process) * num_processes);
        processes[num_processes-1].pid = num_processes;
        processes[num_processes-1].ram_usage = new_ram_usage;
        total_ram_usage += new_ram_usage;

        printf("Process %d created with RAM usage of %d kilobytes. Current RAM usage is %d/%d kilobytes.\n",
            num_processes, new_ram_usage, total_ram_usage, MAX_RAM_USAGE);

    }

    // Cleanup and exit
    free(processes);
    return 0;

}