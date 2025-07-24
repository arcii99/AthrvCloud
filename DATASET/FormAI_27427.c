//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 7777

int main(int argc, char const *argv[]) {
    
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *hello = "Welcome to the future!\nThis is a message from the year 2077.\n";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send message to client
        send(new_socket, hello, strlen(hello), 0);

        // Receive message from client
        char buffer[1024] = {0};
        int valread = read(new_socket, buffer, 1024);
        printf("Client sent the following message: %s\n", buffer);

        // Generate a random number between 1 and 100
        srand(time(NULL));
        int random_number = (rand() % 100) + 1;
        printf("Generated a random number between 1 and 100: %d\n", random_number);

        // Send the random number to client
        char response[1024];
        sprintf(response, "The random number is: %d\n", random_number);
        send(new_socket, response, strlen(response), 0);

        close(new_socket);
        printf("Connection closed\n\n");
    }

    return 0;
}