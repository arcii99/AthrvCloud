//FormAI DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

// Prints error message
void handleError(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "Hello, I am a server.";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handleError("socket failed");
    }
    
    // Attach socket to the given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        handleError("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        handleError("bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        handleError("listen");
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        handleError("accept");
    }

    // Send response to client
    if (send(new_socket, response, strlen(response), 0) < 0) {
        handleError("send failed");
    }
    printf("Response sent to client...\n");

    // Receive message from client
    if (read(new_socket, buffer, 1024) < 0) {
        handleError("read failed");
    }
    printf("Client message: %s\n", buffer);

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}