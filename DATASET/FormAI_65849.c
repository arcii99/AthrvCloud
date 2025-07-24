//FormAI DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    // create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("error creating socket");
        exit(EXIT_FAILURE);
    }

    // define server address
    struct sockaddr_in server_addr;
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET; // ipv4
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 0) {
        perror("error converting IP address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("error connecting to server");
        exit(EXIT_FAILURE);
    }

    // prompt user for input
    printf("Enter message: ");
    char buffer[BUFFER_SIZE] = {0};
    fgets(buffer, BUFFER_SIZE, stdin);

    // send message to server
    send(sock_fd, buffer, strlen(buffer), 0);

    // receive message from server
    char server_buffer[BUFFER_SIZE] = {0};
    int bytes_received = read(sock_fd, server_buffer, BUFFER_SIZE);
    printf("Server response: %s\n", server_buffer);

    // close socket
    close(sock_fd);
    return 0;
}