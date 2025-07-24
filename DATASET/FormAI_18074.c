//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define THREADS 50
#define TIMEOUT 3

int open_socket(char *ip, int port) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        return -1;
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        close(sock);
        return -1;
    }

    return sock;
}

void *scan_port(void *payload) {
    int port = *(int*) payload;
    int sock;
    char *ip = "127.0.0.1"; // Change to target IP

    sock = open_socket(ip, port);
    if (sock != -1) {
        printf("Port %d is open\n", port);
        close(sock);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int ports[THREADS] = {0};
    int i;

    for (i = 0; i < THREADS; i++) {
        ports[i] = i + 1;
    }

    for (i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void*) &ports[i]);
    }

    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}