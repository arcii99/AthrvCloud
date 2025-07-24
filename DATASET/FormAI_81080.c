//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345

int main(){
    int sockfd, client_sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char message[256];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket.");
        exit(1);
    }

    // prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket to address.");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        printf("Failed to listen for incoming connections.");
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {

        // accept incoming connection
        client_len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        if (client_sockfd == -1) {
            printf("Failed to accept incoming connection.");
            continue;
        }

        printf("Client connected from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // read incoming message
        if (read(client_sockfd, message, sizeof(message)) == -1) {
            printf("Failed to read incoming message.");
            close(client_sockfd);
            continue;
        }

        printf("Received message from client: %s.\n", message);

        // send response
        strcpy(message, "Hello from server.");
        if (write(client_sockfd, message, strlen(message)) == -1) {
            printf("Failed to send response message.");
            close(client_sockfd);
            continue;
        }

        printf("Response sent to client.\n");

        // close client socket
        close(client_sockfd);
    }

    // close server socket
    close(sockfd);

    return 0; 
}