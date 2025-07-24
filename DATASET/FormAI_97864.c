//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int num_processes = 0; // Number of processes currently running
    int total_mem_usage = 0; // Total memory usage of all processes
    int avg_mem_usage = 0; // Average memory usage per process
    int max_mem_usage = 0; // Maximum memory usage of all processes

    printf("Greetings! I am a RAM usage monitor program, inspired by Ada Lovelace.\n");

    while (1)
    {
        char buffer[128]; // Buffer to hold system command output
        FILE *output = popen("ps -eo rss | awk '{sum+=$1} END {print sum}'", "r"); // Run system command to get total memory usage of all processes
        fgets(buffer, 128, output); // Get output from system command
        pclose(output); // Close system command output

        int mem_usage = atoi(buffer) / 1024; // Convert output from system command to MB
        num_processes = system("ps aux | wc -l"); // Count number of processes running
        total_mem_usage += mem_usage; // Add current memory usage to total memory usage
        avg_mem_usage = total_mem_usage / num_processes; // Calculate average memory usage per process
        max_mem_usage = (max_mem_usage > mem_usage ? max_mem_usage : mem_usage); // Record maximum memory usage

        printf("Number of processes running: %d\n", num_processes);
        printf("Total memory usage: %d MB\n", total_mem_usage);
        printf("Average memory usage per process: %d MB\n", avg_mem_usage);
        printf("Maximum memory usage: %d MB\n", max_mem_usage);

        sleep(10); // Sleep for 10 seconds before checking again
    }

    return 0;
}