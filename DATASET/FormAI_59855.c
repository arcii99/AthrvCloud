//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    char *server_address = "127.0.0.1";
    int server_port = 8080;

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Error connecting to server");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char *http_request = "GET / HTTP/1.1\r\nHost: localhost:8080\r\nConnection: close\r\n\r\n";
    if (send(socket_fd, http_request, strlen(http_request), 0) == -1) {
        perror("Error sending HTTP request");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char buffer[MAX_BUFFER_SIZE];
    int total_received = 0;
    int num_received;
    while ((num_received = recv(socket_fd, buffer + total_received, MAX_BUFFER_SIZE - total_received, 0)) > 0) {
        total_received += num_received;
        if (total_received >= MAX_BUFFER_SIZE) {
            break;
        }
    }

    if (num_received == -1) {
        perror("Error receiving HTTP response");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // Print HTTP response
    buffer[total_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}