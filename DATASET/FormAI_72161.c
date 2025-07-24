//FormAI DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PORTS 65535
#define THREADS 100

typedef struct ThreadArg {
    int socket;
    struct sockaddr_in address;
    int start_port;
    int end_port;
    int* ports;
} ThreadArg;

void* scanPort(void* arg) {
    ThreadArg* tArg = (ThreadArg*) arg;
    int i, result;

    for (i = tArg->start_port; i <= tArg->end_port; i++) {
        tArg->address.sin_port = htons(i);
        result = connect(tArg->socket, (struct sockaddr*) &tArg->address, sizeof(tArg->address));
        if (result == 0) {
            tArg->ports[i] = 1;
        }
    }
    return NULL;
}

void usage(char* program_name) {
    printf("Usage: %s <target IP address>\n", program_name);
}

int main(int argc, char* argv[]) {
    int i, j;
    int sock;
    struct sockaddr_in target;
    int ports[MAX_PORTS];
    int num_ports = 0;
    int current_port = 0;
    pthread_t threads[THREADS];
    ThreadArg threadArgs[THREADS];

    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;

    if (inet_pton(AF_INET, argv[1], &target.sin_addr) != 1) {
        perror("inet_pton");
        return 1;
    }

    memset(&ports, 0, sizeof(ports));

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sock, (struct sockaddr*) &target, sizeof(target)) != 0) {
        printf("Target is offline or not responding.\n");
        return 1;
    }

    printf("Target is online\n");

    for (i = 0; i < THREADS; i++) {
        threadArgs[i].socket = sock;
        threadArgs[i].address = target;
        threadArgs[i].start_port = current_port;
        current_port += MAX_PORTS/THREADS;
        threadArgs[i].end_port = current_port-1;
        threadArgs[i].ports = ports;
        pthread_create(&threads[i], NULL, scanPort, &threadArgs[i]);
    }

    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_PORTS; i++) {
        if (ports[i] == 1) {
            printf("Port %d is open\n", i);
            num_ports++;
        }
    }

    if (num_ports == 0) {
        printf("No open ports found.\n");
    }

    close(sock);

    return 0;
}