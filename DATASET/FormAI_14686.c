//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Creating socket file descriptor
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        return -1;
    }
    
    // Setting up socket address and port
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Binding socket to the given port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        return -1;
    }
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind the socket");
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        return -1;
    }

    // Accepting incoming connections and sending a welcome message
    int new_socket;
    char *welcome_message = "Welcome to my server!\n";
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            return -1;
        }
        send(new_socket, welcome_message, strlen(welcome_message), 0);
        printf("Welcome message sent to client\n");
    }

    return 0;
}