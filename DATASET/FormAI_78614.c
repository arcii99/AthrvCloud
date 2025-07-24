//FormAI DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int new_socket, valread;
    struct sockaddr_in address;
    char *hello = "Hello from server";
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Specifies the socket address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to a specific address and port
    if (bind(new_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(new_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {

        int client_socket, addrlen = sizeof(address);

        // Accept incoming connection
        if ((client_socket = accept(new_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send message to client
        send(client_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");

        // Receive message from client
        valread = read(client_socket, buffer, 1024);
        printf("%s\n", buffer);
    }

    // Cleanup
    close(new_socket);
    return 0;
}