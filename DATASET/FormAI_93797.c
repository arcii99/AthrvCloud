//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 9002
#define BUFFER_SIZE 256

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Server address structure
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the server address
    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding");
        exit(1);
    }

    // Start listening for incoming connections
    listen(sockfd, 5);
    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections
    int newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(newsockfd < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    printf("Connected to client at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Read input from client and send reply back
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if(bytes_read < 0) {
            perror("Error reading from socket");
            exit(1);
        } else if (bytes_read == 0) {
            printf("Connection closed by client\n");
            break;
        }

        printf("Received: %s\n", buffer);

        // Send reply
        char reply[BUFFER_SIZE];
        strcpy(reply, "ACK: ");
        strcat(reply, buffer);
        int bytes_sent = send(newsockfd, reply, strlen(reply), 0);
        if(bytes_sent < 0) {
            perror("Error sending to socket");
            exit(1);
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}