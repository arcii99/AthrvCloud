//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define NUM_THREADS 10 // Number of threads for multi-threading.
#define SCAN_RANGE 100 // Range of ports to scan.

void *scan_port(void *arg) {
    int port = *((int *) arg);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(port);
    int result = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
    
    if (result == 0) {
        printf("[+] Port %d is open.\n", port);
    }
    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int ports[SCAN_RANGE];
    int i, j;
    
    for (i = 0; i < SCAN_RANGE; i++) {
        ports[i] = i;
    }
    
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i * SCAN_RANGE/NUM_THREADS;
        pthread_create(&threads[i], NULL, scan_port, &thread_args[i]);
    }
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("[*] Port scanning finished.\n");
    
    return 0;
}