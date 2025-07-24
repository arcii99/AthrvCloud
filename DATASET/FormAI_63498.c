//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize socket address
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket and listen
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Socket binding failed\n");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) == -1) {
        perror("Listen failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    // Accept connection and receive message
    int client_fd;
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) == -1) {
            perror("Server accept failed\n");
            exit(EXIT_FAILURE);
        }
        printf("New connection established\n");
        char buffer[BUFFER_SIZE] = {0};
        read(client_fd, buffer, BUFFER_SIZE);
        printf("Client message received: %s", buffer);

        // Send a happy response
        char response[] = "Yay! I received your message! :)";
        write(client_fd, response, strlen(response));
        printf("Response sent\n");

        close(client_fd);
    }
    return 0;
}