//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

void* monitor_cpu_usage(void* arg) {
    int cpu_usage;
    printf("Monitoring CPU usage... Press CTRL+C to stop.\n");
    while (1) {
        // Get CPU usage
        FILE* fp = fopen("/proc/stat", "r");
        fscanf(fp, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n");
        fscanf(fp, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d\n", &cpu_usage);
        fclose(fp);

        // Print usage bar
        printf("CPU Usage: [");
        for (int i = 0; i < 50; i++) {
            if (i < cpu_usage / 2) {
                printf(COLOR_GREEN "#");
            } else {
                printf(COLOR_RED "#");
            }
        }
        printf(COLOR_RESET "]\n");

        // Wait 1 second
        sleep(1);
    }
}

int main() {
    pthread_t thread;
    int status = pthread_create(&thread, NULL, monitor_cpu_usage, NULL);
    if (status != 0) {
        printf("Error starting monitor thread!");
        exit(1);
    }
    pthread_join(thread, NULL);
    return 0;
}