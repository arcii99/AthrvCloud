//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define MAX_QOS 10

typedef struct {
    int priority;
    int bandwidth;
    int latency;
    int jitter;
} QoS;

int main(int argc, char *argv[]) {
    int port = 8888;
    int sockfd, newsockfd, clientlen, n;
    struct sockaddr_in servaddr, clientaddr;
    char buf[MAX_BUF_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

    // Initialize server address
    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons((unsigned short)port);

    // Bind socket
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, 5);

    // Initialize array of QoS objects
    QoS qos[MAX_QOS];
    int i;
    for (i = 0; i < MAX_QOS; i++) {
        qos[i].priority = 0;
        qos[i].bandwidth = 0;
        qos[i].latency = 0;
        qos[i].jitter = 0;
    }

    while (1) {
        // Accept incoming connections
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Receive QoS info from client
        bzero(buf, MAX_BUF_SIZE);
        n = read(newsockfd, buf, MAX_BUF_SIZE);

        // Parse QoS info and update qos array
        int priority, bandwidth, latency, jitter;
        sscanf(buf, "%d %d %d %d", &priority, &bandwidth, &latency, &jitter);
        if (priority >= 0 && priority < MAX_QOS) {
            qos[priority].priority = priority;
            qos[priority].bandwidth = bandwidth;
            qos[priority].latency = latency;
            qos[priority].jitter = jitter;
        }

        // Send confirmation to client
        n = write(newsockfd, "QoS received\n", strlen("QoS received\n"));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Close connection
        close(newsockfd);
    }

    return 0;
}