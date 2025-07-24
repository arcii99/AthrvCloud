//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4

void *monitor_cpu(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    while(1) {
        char cmd[100];
        sprintf(cmd, "ps -p %d -o %%cpu | tail -1", getpid());
        FILE* fp = popen(cmd, "r");
        char buffer[1024];
        fgets(buffer, sizeof(buffer), fp);
        float cpu_usage = atof(buffer);
        printf("Thread #%ld CPU Usage: %.1f%%\n", tid, cpu_usage);
        pclose(fp);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, monitor_cpu, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}