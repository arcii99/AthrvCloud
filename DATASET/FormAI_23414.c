//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_cpu_usage = 0;
    int max_cpu_usage = 0;
    int min_cpu_usage = 100;
    int total_cpu_usage = 0;
    int count = 0;
    srand(time(NULL)); 

    printf("Welcome to the Medieval CPU Usage Monitor!\n\n");

    printf("Time\t\tCPU usage\n");
    printf("-----------------------\n");

    for (int i = 0; i < 10; i++) {
        // Generate a random CPU usage between 0 and 100
        current_cpu_usage = rand() % 101;

        // Update max CPU usage if necessary
        if (current_cpu_usage > max_cpu_usage) {
            max_cpu_usage = current_cpu_usage;
        }

        // Update min CPU usage if necessary
        if (current_cpu_usage < min_cpu_usage) {
            min_cpu_usage = current_cpu_usage;
        }

        // Increment total CPU usage
        total_cpu_usage += current_cpu_usage;

        // Print current CPU usage
        printf("%d\t\t%d%%\n", i+1, current_cpu_usage);

        // Delay for one second (in medieval style!)
        for (int j = 0; j < 100000000; j++) {
            // Do nothing (medieval style!)
        }

        count++;
    }

    float avg_cpu_usage = (float) total_cpu_usage / count;

    printf("-----------------------\n");
    printf("Average CPU usage: %.2f%%\n", avg_cpu_usage);
    printf("Max CPU usage: %d%%\n", max_cpu_usage);
    printf("Min CPU usage: %d%%\n", min_cpu_usage);

    return 0;
}