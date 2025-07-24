//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 // Port number
#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    int client_addr_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, (socklen_t*)&client_addr_len);
    if (new_sockfd < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    // Get client name and age
    char name[BUFFER_SIZE];
    char age[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE); // Clear buffer
    read(new_sockfd, buffer, BUFFER_SIZE);
    strncpy(name, buffer, BUFFER_SIZE);
    bzero(buffer, BUFFER_SIZE); // Clear buffer
    read(new_sockfd, buffer, BUFFER_SIZE);
    strncpy(age, buffer, BUFFER_SIZE);
    printf("Client name: %s\n", name);
    printf("Client age: %s\n", age);

    // Reply to client with welcome message
    char welcome_msg[BUFFER_SIZE];
    sprintf(welcome_msg, "Welcome, %s! Your age is %s.", name, age);
    send(new_sockfd, welcome_msg, strlen(welcome_msg), 0);

    // Close sockets
    close(new_sockfd);
    close(sockfd);

    return 0;
}