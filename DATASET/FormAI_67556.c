//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int socket_fd, new_socket_fd, sockfd;
    struct sockaddr_in servaddr, clientaddr;
    char buffer[MAX_BUFFER_SIZE];
    char *server_message = "Server is up and running!";

    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options to reuse the address
    int reuse = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to localhost on port 8080
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        unsigned int len = sizeof(clientaddr);

        // Accept connections from new clients
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&clientaddr, &len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send the welcome message to the newly connected client
        send(new_socket_fd, server_message, strlen(server_message), 0);
        printf("Welcome message sent to client\n");

        // Receive data from the client
        int n = read(new_socket_fd, buffer, MAX_BUFFER_SIZE);
        buffer[n] = '\0';
        printf("Received message from client: %s\n", buffer);

        // Reverse the message and send it back to the client
        int len_buff = strlen(buffer);
        for(int i=0; i < len_buff/2; i++) {
            char temp = buffer[i];
            buffer[i] = buffer[len_buff - i - 1];
            buffer[len_buff - i - 1] = temp;
        }
        send(new_socket_fd, buffer, strlen(buffer), 0);
        printf("Reversed message sent to client: %s\n", buffer);
    }

    // Close the socket
    close(socket_fd);
    return 0;
}