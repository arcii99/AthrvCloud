//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/resource.h>

// Function to get CPU usage percentage
double get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double seconds = (double)(usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) + (double)(usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000.0;
    double cpu_usage = 100.0 * seconds / (double)sysconf(_SC_CLK_TCK);
    return cpu_usage;
}

// Thread function to continuously print CPU usage
void* print_cpu_usage(void* thread_id) {
    int id = *(int*)thread_id;
    while(1) {
        printf("Thread %d CPU Usage: %.2f%%\n", id, get_cpu_usage());
        usleep(1000000);
    }
    pthread_exit(NULL);
}

// Main method to create and run multiple threads
int main() {
    int num_threads;
    printf("Enter number of threads to create: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    printf("Creating %d threads...\n", num_threads);

    for(int i=0; i<num_threads; i++) {
        thread_ids[i] = i+1;
        int rc = pthread_create(&threads[i], NULL, print_cpu_usage, &thread_ids[i]);
        if(rc) {
            printf("Error: Unable to create thread %d\n", i+1);
            exit(1);
        }
    }

    pthread_exit(NULL);
}