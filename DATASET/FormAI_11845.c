//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define NUM_THREADS 2

typedef struct {
    int thread_id;
    int memory_usage;
} ThreadData;

void* get_memory_usage(void* thread_data) {
    ThreadData* data = (ThreadData*) thread_data;
    int pid = getpid();
    char command[50];
    sprintf(command, "cat /proc/%d/status", pid);
    FILE* fp = popen(command, "r");
    if (fp) {
        char buffer[256];
        while (fgets(buffer, 256, fp) != NULL) {
            if (strstr(buffer, "VmRSS")) {
                sscanf(buffer, "VmRSS: %d kB", &data->memory_usage);
            }
        }
        pclose(fp);
    }
    pthread_exit(NULL);
}

void* monitor_memory_usage(void* thread_data) {
    ThreadData* data = (ThreadData*) thread_data;
    while (1) {
        pthread_t threads[NUM_THREADS];
        ThreadData thread_data[NUM_THREADS];
        int rc;
        long t;
        for (t = 0; t < NUM_THREADS; t++) {
            thread_data[t].thread_id = t;
            thread_data[t].memory_usage = 0;
            rc = pthread_create(&threads[t], NULL, get_memory_usage, (void*) &thread_data[t]);
            if (rc) {
                printf("ERROR: return code from pthread_create() is %d\n", rc);
                exit(-1);
            }
        }
        for (t = 0; t < NUM_THREADS; t++) {
            rc = pthread_join(threads[t], NULL);
            if (rc) {
                printf("ERROR: return code from pthread_join() is %d\n", rc);
                exit(-1);
            }
            printf("Thread %d memory usage: %d kB\n", thread_data[t].thread_id, thread_data[t].memory_usage);
            data->memory_usage += thread_data[t].memory_usage;
        }
        printf("Total Memory Usage: %d kB\n", data->memory_usage);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t monitor_thread;
    ThreadData thread_data;
    int rc;
    long t;

    rc = pthread_create(&monitor_thread, NULL, monitor_memory_usage, (void*) &thread_data);
    if (rc) {
        printf("ERROR: return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    pthread_exit(NULL);
}