//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define THREADS_COUNT 4

void *pingServer(void *arguments);

struct arguments {
    int threadId;
    char *ipAddress;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./internet-speed-test <ip_address>\n");
        return 1;
    }
    char *ipAddress = argv[1];

    pthread_t threads[THREADS_COUNT];
    struct arguments args[THREADS_COUNT];

    for (int i = 0; i < THREADS_COUNT; i++) {
        args[i].threadId = i;
        args[i].ipAddress = ipAddress;
        pthread_create(&threads[i], NULL, pingServer, (void*)&args[i]);
    }

    for (int i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *pingServer(void *arguments) {
    struct arguments *args = (struct arguments*)arguments;
    int threadId = args->threadId;
    char *ipAddress = args->ipAddress;

    char command[128];
    sprintf(command, "ping -c 10 %s | grep 'rtt' | awk '{ print $4 }' | cut -d'/' -f2", ipAddress);

    FILE *pipe = popen(command, "r");
    if (!pipe) {
        printf("Thread %d failed to execute command\n", threadId);
        pthread_exit(NULL);
    }

    char buffer[128];
    int index = 0;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        if (strstr(buffer, "time=") != NULL) {
            index += sprintf(buffer+index, "%s", buffer);
        }
    }
    if (pclose(pipe) == -1) {
        printf("Thread %d failed to close pipe\n", threadId);
        pthread_exit(NULL);
    }

    if (index == 0) {
        printf("Thread %d failed to retrieve time\n", threadId);
        pthread_exit(NULL);
    }

    double time = atof(buffer);
    printf("Thread %d retrieved time: %.2f ms\n", threadId, time);

    pthread_exit(NULL);
}