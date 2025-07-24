//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main(int argc, char const *argv[]) {
    int sockfd, newsockfd, client_len, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG_LEN] = {0};
    char response[] = "Server: Message received\n";
    
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Forcing a bind on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons( PORT );

    // Bind the socket to the specified port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port: %d\n", PORT);

    while (1) {
        client_len = sizeof(client_addr);

        // Accept incoming connection
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read incoming message from client
        if (read(newsockfd, buffer, MAX_MSG_LEN) < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Client: %s\n", buffer);

        // Send response to client
        if (write(newsockfd, response, strlen(response)) < 0) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
        close(newsockfd);
    }

    return 0;
}