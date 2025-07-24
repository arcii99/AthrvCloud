//FormAI DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("STATISTICAL SYSTEM ADMINISTRATION EXAMPLE PROGRAM\n\n");
    
    // Initialize random seed
    srand(time(0));
    
    // Generate random number to simulate CPU usage
    int cpu_usage = (rand() % 101);
    
    // Generate random number to simulate memory usage
    int mem_usage = (rand() % 401) + 100; // memory usage between 100 and 500 MB
    
    // Generate random number to simulate disk usage
    double disk_usage = ((double) rand() / RAND_MAX) * 100; // disk usage between 0 and 100%
    
    // Simulate database query times
    int query_times[10];
    for (int i = 0; i < 10; i++) {
        query_times[i] = (rand() % 401) + 100; // query times between 100 and 500 ms
    }
    
    // Calculate average query time
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += query_times[i];
    }
    double avg_query_time = sum / 10;
    
    // Print system information
    printf("CPU Usage: %d%%\n", cpu_usage);
    printf("Memory Usage: %d MB\n", mem_usage);
    printf("Disk Usage: %.2f%%\n", disk_usage);
    printf("Average Query Time: %.2f ms\n", avg_query_time);
    
    // Check if system is overloaded
    if (cpu_usage >= 90 || mem_usage >= 350 || disk_usage >= 80 || avg_query_time >= 300) {
        printf("\nWARNING: System is overloaded!\n");
    }
    
    return 0;
}