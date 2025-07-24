//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    
    int sock_fd;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address values
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to the server
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // Reading message from user
        printf("Enter message to send to server: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Sending message to server
        if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        // Receiving message from server
        if (recv(sock_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        printf("Received message from server: %s", buffer);
    }

    return 0;
}