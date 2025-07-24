//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 256

void *mapper(void *arg) {
    char *hostname = (char *)arg;
    struct hostent *host;

    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: Cannot resolve hostname '%s'\n", hostname);
        return NULL;
    }

    struct in_addr **addr_list;
    addr_list = (struct in_addr **)host->h_addr_list;

    for (int i = 0; addr_list[i] != NULL; i++) {
        char *ip = inet_ntoa(*addr_list[i]);
        printf("%s\n", ip);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname> [hostname2 ...]\n", argv[0]);
        return 1;
    }

    int num_hosts = argc - 1;

    if (num_hosts > MAX_THREADS) {
        printf("Error: Too many hosts. Maximum is %d\n", MAX_THREADS);
        return 1;
    }

    pthread_t threads[num_hosts];

    for (int i = 1; i <= num_hosts; i++) {
        char *hostname = argv[i];
        pthread_create(&threads[i-1], NULL, mapper, hostname);
    }

    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}