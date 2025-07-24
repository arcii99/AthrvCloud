//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    char *response = "HTTP/1.1 200 OK\r\n Content-Type: text/html\r\n\r\n <html><body><h1>Welcome to the curious C web server!</h1><p>Thanks for visiting.</p></body></html>";
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to the given port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        printf("Curious C Web server is waiting for client connection...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from client!\n");

        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);

        printf("Request received from client:\n%s\n", buffer);

        write(new_socket, response, strlen(response));

        printf("Response sent to client.\n");

        close(new_socket);
    }
    return 0;
}