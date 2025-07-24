//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_PORTS 100
#define HOSTNAME "127.0.0.1"

pthread_mutex_t mutex;

void *scan_port(void *port_ptr) {
    int port = *((int *)port_ptr);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOSTNAME);
    server.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        printf("socket creation error\n");
        exit(1);
    }
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        pthread_mutex_lock(&mutex);
        printf("[+] Port %d is open.\n", port);
        pthread_mutex_unlock(&mutex);
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int start_port = rand() % 9999 + 1; // Pick a random start port
    int end_port = start_port + MAX_PORTS;
    
    pthread_t threads[MAX_THREADS];
    int ports[MAX_PORTS];
    int num_ports = 0;

    for (int i = start_port; i < end_port; i++) {
        ports[num_ports++] = i;
    }

    printf("[*] Scanning %d ports on %s...\n", num_ports, HOSTNAME);

    int port_index = 0;
    int thread_index = 0;

    while (port_index < num_ports) {
        if (thread_index == MAX_THREADS) {
            thread_index = 0;
            sleep(1);
            continue;
        }

        int port = ports[port_index++];
        pthread_create(&threads[thread_index++], NULL, scan_port, &port);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("[*] Scan complete.\n");
    return 0;
}