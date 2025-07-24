//FormAI DATASET v1.0 Category: Simple Web Server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void send_response(int client_sock, char *html_response) {
    char http_head[2048] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    char http_body[2048];
    sprintf(http_body, "%s", html_response);
    write(client_sock, http_head, strlen(http_head));
    write(client_sock, http_body, strlen(http_body));
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[30000] = {0};
    char *html_response = "<html><head><title>Simple HTML Example</title></head><body><h1>Welcome to my Simple Web Server!</h1></body></html>";

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assign IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to defined IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected\n");

        // Read incoming request from client
        valread = read(new_socket, buffer, 30000);
        printf("%s\n", buffer);

        // Send HTML response back to client
        send_response(new_socket, html_response);

        printf("Response sent\n");
        close(new_socket);
    }

    return 0;
}