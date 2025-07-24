//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_THREADS 50
#define TIMEOUT 3

pthread_mutex_t lock;

// Function to scan the wireless network for a given IP and port
void *scan_network(void *arg) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sockfd, result;
    char ip[20];
    int port = *(int *) arg;

    // Get mutex lock to avoid race conditions
    pthread_mutex_lock(&lock);

    printf("Scanning on port %d...\n", port);

    // Scan the network
    for (int i = 1; i <= 255; i++) {
        sprintf(ip, "192.168.1.%d", i);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            pthread_exit(NULL);
        }

        he = gethostbyname(ip);
        if (he == NULL) {
            herror("gethostbyname");
            pthread_exit(NULL);
        }

        memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        if (result == 0) {
            printf("Found a device at %s port %d!\n", ip, port);
        }

        close(sockfd);
        sleep(TIMEOUT); // Wait for TIMEOUT seconds before trying another IP address
    }

    printf("Done scanning on port %d.\n", port);

    // Release mutex lock
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ports[MAX_THREADS] = {80, 443, 8080, 8443};
    int rc, i;

    printf("Starting the wireless network scanner...\n");

    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // Create threads for each port
    for (i = 0; i < MAX_THREADS; ++i) {
        rc = pthread_create(&threads[i], NULL, scan_network, (void *) &ports[i]);
        if (rc) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish executing
    for (i = 0; i < MAX_THREADS; ++i) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    // Clean up mutex lock
    pthread_mutex_destroy(&lock);

    printf("Wireless network scan complete.\n");

    return 0;
}