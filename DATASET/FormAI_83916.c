//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define NUM_THREADS 2
#define CPU_INTERVAL 3
#define CPU_USAGE_SCALE 100

struct thread_info {
    pthread_t tid;
    int thread_num;
};

typedef struct thread_info ThreadInfo;

void *getCpuUsage(void *arg) {
    ThreadInfo *info = (ThreadInfo *) arg;

    pid_t tid = syscall(SYS_gettid);
    printf("[THREAD %d] Thread ID: %d\n", info->thread_num, tid);

    while (1) {
        char cmd[50];
        sprintf(cmd, "ps -p %d -o %%cpu | tail -n +2", tid);

        FILE *fpipe = popen(cmd, "r");
        if (!fpipe) {
            printf("[THREAD %d] Failed to run command\n", info->thread_num);
            pthread_exit(NULL);
        }

        char line[20];
        fgets(line, sizeof(line), fpipe);
        float cpuUsage = atof(line);
        cpuUsage /= CPU_USAGE_SCALE;

        printf("[THREAD %d] CPU Usage: %.2f%%\n", info->thread_num, cpuUsage);

        pclose(fpipe);
        sleep(CPU_INTERVAL);
    }
}

int main(int argc, char *argv[]) {
    ThreadInfo thread_info[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_info[i].thread_num = i;

        rc = pthread_create(&(thread_info[i].tid), NULL, getCpuUsage, &(thread_info[i]));
        if (rc) {
            printf("[MAIN] Error: Return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    pthread_exit(NULL);
}