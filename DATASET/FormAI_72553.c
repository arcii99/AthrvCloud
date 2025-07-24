//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *monitor(void *arg);
void *server(void *arg);

int main(int argc, char const *argv[]) {
    pthread_t monitor_thread, server_thread;

    // Create thread for QoS monitor
    if (pthread_create(&monitor_thread, NULL, monitor, NULL) != 0) {
        fprintf(stderr, "Error: Failed to create monitor thread.\n");
        exit(1);
    }

    // Create thread for QoS server
    if (pthread_create(&server_thread, NULL, server, NULL) != 0) {
        fprintf(stderr, "Error: Failed to create server thread.\n");
        exit(1);
    }

    // Wait for threads to finish execution
    pthread_join(monitor_thread, NULL);
    pthread_join(server_thread, NULL);

    return 0;
}

void *monitor(void *arg) {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    // Create socket for monitoring network
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Assign IP, PORT and protocol to the socket address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Failed to bind socket.\n");
        exit(1);
    }

    while (1) {
        // Receive QoS messages
        memset(buffer, 0, sizeof(buffer));
        if (recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, NULL, NULL) < 0) {
            fprintf(stderr, "Error: Failed to receive QoS message.\n");
            exit(1);
        }

        // Display received QoS message
        printf("Received QoS message: %s", buffer);
    }
}

void *server(void *arg) {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create server socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Assign IP, PORT and protocol to the socket address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Failed to bind socket.\n");
        exit(1);
    }

    while (1) {
        // Wait for clients to connect
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));
        socklen_t len;
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE,
                         MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);

        // Display client IP and PORT address
        printf("Connection from %s:%d\n",
               inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        // Send QoS response to client
        char *msg = "Connection successful!\n";
        sendto(sockfd, (const char *)msg, strlen(msg),
               MSG_CONFIRM, (const struct sockaddr *)&cliaddr, sizeof(cliaddr));

        // Send QoS messages
        const char *qos_msg = "5Mbps\n";
        for (int i = 0; i < 10; i++) {
            sendto(sockfd, (const char *)qos_msg, strlen(qos_msg),
                   MSG_CONFIRM, (const struct sockaddr *)&cliaddr, sizeof(cliaddr));
            sleep(1);
        }
    }
}