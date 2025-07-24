//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_BUFF_SIZE 1024

int main () {
    int sockfd;
    int buff_size;
    char *server_ip = "127.0.0.1";
    char buffer[MAX_BUFF_SIZE];
    struct sockaddr_in servaddr;

    // create socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // check if socket was created successfully
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // configure settings of the sockaddr_in structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(server_ip);

    // bind the socket with the sockaddr_in structure
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    // infinite loop to receive messages
    while (1) {
        // receive message from client
        buff_size = recvfrom(sockfd, buffer, MAX_BUFF_SIZE, 0, NULL, NULL);

        // print received message
        printf("Message received: %s\n", buffer);

        // check network quality of service
        if (buff_size < 0) {
            printf("Error receiving message\n");
        } else if (buff_size < 1024) {
            printf("Network quality of service is low\n");
        } else {
            printf("Network quality of service is good\n");
        }

        // clear buffer
        memset(buffer, 0, MAX_BUFF_SIZE);
    }

    // close the socket
    close(sockfd);

    return 0;
}