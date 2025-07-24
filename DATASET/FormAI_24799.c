//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {

    // Creating socket file descriptor
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept and serve incoming connection requests
    int client_socket;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    while ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen))) {
        printf("\nConnection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read request from client
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, 1024);
        printf("%s", buffer);

        // Prepare response header
        char header[1024];
        memset(header, 0, sizeof(header));
        sprintf(header, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n");

        // Write response header to client
        write(client_socket, header, strlen(header));

        // Write response body to client
        char body[1024];
        memset(body, 0, sizeof(body));
        sprintf(body, "<html><body><h1>Hello, Future World!</h1></body></html>");
        write(client_socket, body, strlen(body));

        // Close client socket
        close(client_socket);
        printf("\nConnection closed from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    // Close server socket
    close(server_fd);

    return 0;
}