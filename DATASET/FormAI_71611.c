//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define THREAD_NUM 100	// Maximum number of threads
#define MAX_PORTS 65535	// Maximum number of ports

// Thread function
void *scan_thread(void *arg) {

    int sfd;
    struct sockaddr_in target_addr;
    int *ports = (int*)arg;

    // Create socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Target address
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(*ports);
    target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Connect to target address
    if (connect(sfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0) {
        printf("Port %d open\n", *ports);
    }

    close(sfd);
    pthread_exit(NULL);
}

int main(int argc , char *argv[]) {

    if (argc != 2) {
        printf("Usage : %s <ip_address>\n",argv[0]);
        return EXIT_FAILURE;
    }

    int ports[MAX_PORTS];
    int num_ports = 0;

    // Fill the array of ports
    for (int i = 0; i < MAX_PORTS; i++) {
        ports[i] = i + 1;
        num_ports++;
    }

    // Shuffle the array of ports
    srand(time(NULL));
    for (int i = 0; i < num_ports; i++) {
        int j = rand() % num_ports;
        int temp = ports[i];
        ports[i] = ports[j];
        ports[j] = temp;
    }

    pthread_t threads[THREAD_NUM];
    int thread_count = 0;

    // Launch threads
    for (int i = 0; i < num_ports; i++) {

        // Check if maximum number of threads reached
        if (thread_count == THREAD_NUM) {
            for (int j = 0; j < THREAD_NUM; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        // Launch thread
        if (pthread_create(&threads[thread_count], NULL, scan_thread, &ports[i])) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
        thread_count++;
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}