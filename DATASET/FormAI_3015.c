//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to hold system information
typedef struct {
    int memory;
    int cpu_usage;
    int disk_usage;
} SystemInfo;

// Function to collect system information
void* collect_sys_info(void* arg) {
    SystemInfo* info = (SystemInfo*) arg;
    // Code to collect system information here
    return NULL;
}

int main() {
    // Create pthread variables for each system information collector
    pthread_t memory_thread, cpu_thread, disk_thread;
    SystemInfo memory_info, cpu_info, disk_info;

    // Create threads to collect system information
    pthread_create(&memory_thread, NULL, collect_sys_info, (void*) &memory_info);
    pthread_create(&cpu_thread, NULL, collect_sys_info, (void*) &cpu_info);
    pthread_create(&disk_thread, NULL, collect_sys_info, (void*) &disk_info);

    // Wait for all threads to complete before printing results
    pthread_join(memory_thread, NULL);
    pthread_join(cpu_thread, NULL);
    pthread_join(disk_thread, NULL);

    // Print system information
    printf("Memory usage: %d\n", memory_info.memory);
    printf("CPU usage: %d%%\n", cpu_info.cpu_usage);
    printf("Disk usage: %d%%\n", disk_info.disk_usage);

    return 0;
}