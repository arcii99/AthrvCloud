//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    float cpu_usage;
} Process;

int main() {
    Process processes[MAX_PROCESSES];
    time_t start, end;
    float total_cpu_usage;
    int num_processes = 0;

    // Get the number of CPUs for the system
    int num_cpus = get_nprocs();

    // Start the timer
    start = time(NULL);
    for(int i = 0; i < MAX_PROCESSES; i++) {
        // Generate a random CPU usage between 0 and 100
        float cpu_usage = ((float)rand() / RAND_MAX) * 100;

        // Check if the CPU usage is over 50%
        if(cpu_usage > 50) {
            // Create a new process
            Process process;
            process.pid = i;
            process.cpu_usage = cpu_usage;

            // Add the process to the array of processes
            processes[num_processes] = process;
            num_processes++;

            // Print the process info to the console
            printf("Process %d created with CPU usage: %f\n", process.pid, process.cpu_usage);
        }
    }

    // Get the current CPU usage
    struct sysinfo info;
    if(sysinfo(&info) != 0) {
        printf("Error: could not get system info\n");
        exit(1);
    }

    // Calculate the total CPU usage
    total_cpu_usage = ((((float)info.loads[0] / (1 << SI_LOAD_SHIFT)) / num_cpus) * 100);

    // Print the CPU usage to the console
    printf("Current CPU usage: %f%%\n", total_cpu_usage);

    // Wait for 5 seconds
    sleep(5);

    // Get the current CPU usage again
    if(sysinfo(&info) != 0) {
        printf("Error: could not get system info\n");
        exit(1);
    }

    // Calculate the total CPU usage again
    total_cpu_usage = ((((float)info.loads[0] / (1 << SI_LOAD_SHIFT)) / num_cpus) * 100);

    // Print the CPU usage to the console
    printf("Updated CPU usage: %f%%\n", total_cpu_usage);

    // Calculate the CPU usage for each process
    for(int i = 0; i < num_processes; i++) {
        float cpu_usage = processes[i].cpu_usage / total_cpu_usage;
        printf("Process %d CPU usage: %f%%\n", processes[i].pid, cpu_usage);
    }

    // Calculate the total time elapsed
    end = time(NULL);
    printf("Elapsed time: %ld seconds\n", end - start);

    return 0;
}