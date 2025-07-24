//FormAI DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 100

void *scan_port(void *ptr) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = { 0 };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(*(int *)ptr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open!\n", *(int *)ptr);
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    int start_port = 1, end_port = 65535;
    bool ports_open[65536] = { false };

    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS] = { 0 };
    int t = 0;

    for (int i = start_port; i <= end_port; i++) {
        args[t] = i;
        if (pthread_create(&threads[t], NULL, scan_port, &args[t])) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        t++;

        if (t == NUM_THREADS || i == end_port) {
            for (int j = 0; j < t; j++) {
                pthread_join(threads[j], NULL);
            }
            t = 0;
        }
    }

    return 0;
}