//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

int MIN_PORT = 1;
int MAX_PORT = 65535;
int NUM_THREADS = 100;

void *scan_ports(void *arg) {
    char *ip = (char *) arg;

    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket() failed");
            exit(1);
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <ip>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int ports_per_thread = (MAX_PORT - MIN_PORT + 1) / NUM_THREADS;

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int start_port = MIN_PORT + i * ports_per_thread;
        int end_port = i == NUM_THREADS - 1 ? MAX_PORT : start_port + ports_per_thread - 1;
        char range[100];
        snprintf(range, sizeof(range), "%s:%d-%d", ip, start_port, end_port);
        pthread_create(&threads[i], NULL, scan_ports, (void *) range);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}