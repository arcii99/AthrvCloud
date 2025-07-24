//FormAI DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {

    int server_fd, client_fd, valread;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        return -1;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return -1;
    }

    // Wait for connections
    unsigned int addrlen = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        return -1;
    }

    // Handle connections
    while (1) {
        memset(buffer, 0, BUF_SIZE);

        // Read data from client
        valread = read(client_fd, buffer, BUF_SIZE);
        if (valread < 0) {
            perror("Read failed");
            break;
        }

        // Echo data back to client
        if (write(client_fd, buffer, strlen(buffer)) < 0) {
            perror("Write failed");
            break;
        }
    }

    // Close connections
    close(client_fd);
    close(server_fd);

    return 0;
}