//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* monitor_memory(void* arg);

int main() {
    pthread_t tid;
    pthread_attr_t attr;

    // Initialize attributes
    pthread_attr_init(&attr);
    
    // Create thread
    pthread_create(&tid, &attr, monitor_memory, NULL);
    
    // Join thread
    pthread_join(tid, NULL);

    pthread_exit(NULL);
}

void* monitor_memory(void* arg) {
    // Continuously check and print current RAM usage
    while(1) {
        FILE* file = fopen("/proc/meminfo", "r");

        if (file != NULL) {
            char buffer[256];
            int ram_in_kb = 0;

            while (fgets(buffer, sizeof(buffer), file)) {
                // Search for "MemAvailable:" string in file
                if (sscanf(buffer, "MemAvailable: %d", &ram_in_kb) == 1) {
                    printf("Current RAM usage: %d\n", ram_in_kb);
                    break;
                }
            }

            fclose(file);
        }
        
        sleep(5);
    }

    return NULL;
}