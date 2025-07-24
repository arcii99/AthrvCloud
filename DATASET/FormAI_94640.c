//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, opt = 1;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *hello = "Hello from the server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while(1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Accepted new connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receive data from the client
        int read_size;
        while((read_size = read(new_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
            printf("Received %d bytes from client: %s\n", read_size, buffer);

            // Send response back to the client
            send(new_socket, hello, strlen(hello), 0);
            printf("Response sent to client: %s\n", hello);

            memset(buffer, 0, MAX_BUFFER_SIZE); // Reset buffer
        }

        if (read_size == 0) {
            printf("Connection closed\n");
        }
        else if (read_size == -1) {
            perror("recv");
        }
    }

    return 0;
}