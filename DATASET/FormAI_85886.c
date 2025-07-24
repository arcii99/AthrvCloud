//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    /* Step 1: Create the socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    /* Step 2: Bind the socket to a specific IP address and port */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    /* Step 3: Listen for incoming connections */
    if (listen(server_fd, 3) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    /* Step 4: Accept incoming connections and process data */
    socklen_t client_size = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_size);
    if (client_fd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("New connection accepted from %s:%d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    int bytes_read;
    while ((bytes_read = read(client_fd, buffer, sizeof(buffer))) > 0) {
        printf("Message received: %s\n", buffer);
        write(client_fd, buffer, bytes_read);
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytes_read == 0) {
        printf("Connection closed by client.\n");
    } else {
        perror("Error receiving data");
    }

    close(client_fd);
    close(server_fd);

    return 0;
}