//FormAI DATASET v1.0 Category: Socket programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_client(int socket_fd) {
    char buffer[1024] = {0};
    int valread = read(socket_fd, buffer, 1024);

    printf("Client: %s", buffer);

    char *response = "Hello from the server!\n";
    write(socket_fd, response, strlen(response));
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(server_address);

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set sock options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;         
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle the client request in a new process
        if (fork() == 0) {
            close(server_fd);
            handle_client(client_fd);
            exit(0);
        }

        // Close the client file descriptor
        close(client_fd);
    }

    return 0;
}