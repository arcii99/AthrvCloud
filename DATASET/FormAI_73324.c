//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define RANGE 1024

struct scan_thread_args {
    char *ip;
    int start_port;
    int end_port;
};

void *scan_thread(void *args) {
    struct scan_thread_args *scan_args = (struct scan_thread_args *)args;
    int sock, conn;
    struct sockaddr_in target;
    int port;

    target.sin_family = AF_INET;

    for (port = scan_args->start_port; port <= scan_args->end_port; port++) {
        target.sin_port = htons(port);
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Socket error: %s\n", strerror(errno));
            return NULL;
        }

        inet_pton(AF_INET, scan_args->ip, &target.sin_addr);
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) >= 0) {
            printf("%d open\n", port);
        } else {
            close(sock);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int start_port = 1, end_port = RANGE;
    int num_threads = 1;
    pthread_t threads[MAX_THREADS];
    struct scan_thread_args *thread_args;
    int i, j;

    if (argc < 2 || argc > 4) {
        printf("Usage: %s <ip address> [start port] [end port] [num threads]\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    if (argc >= 3) {
        start_port = atoi(argv[2]);
        if (start_port < 1 || start_port > RANGE) {
            printf("Invalid starting port number (should be between 1 and %d)\n", RANGE);
            return 1;
        }
    }
    if (argc >= 4) {
        end_port = atoi(argv[3]);
        if (end_port < 1 || end_port > RANGE) {
            printf("Invalid ending port number (should be between 1 and %d)\n", RANGE);
            return 1;
        }
        if (end_port < start_port) {
            printf("Ending port cannot be less than starting port.\n");
            return 1;
        }
    }
    if (argc == 5) {
        num_threads = atoi(argv[4]);
        if (num_threads < 1 || num_threads > MAX_THREADS) {
            printf("Invalid number of threads (should be between 1 and %d)\n", MAX_THREADS);
            return 1;
        }
    }

    printf("Scanning %s from port %d to %d using %d thread(s).\n", ip, start_port, end_port, num_threads);

    int ports_per_thread = (end_port - start_port + 1) / num_threads;
    int remainder_ports = (end_port - start_port + 1) % num_threads;
    int port_counter = start_port;
    for (i = 0; i < num_threads; i++) {
        thread_args = (struct scan_thread_args *)malloc(sizeof(struct scan_thread_args));
        thread_args->ip = ip;
        thread_args->start_port = port_counter;
        port_counter += ports_per_thread;
        if (remainder_ports > 0) {
            port_counter++;
            remainder_ports--;
        }
        thread_args->end_port = port_counter - 1;
        if (pthread_create(&threads[i], NULL, scan_thread, (void *)thread_args) != 0) {
            printf("Thread creation error.\n");
            return 1;
        }
    }

    for (j = 0; j < num_threads; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}