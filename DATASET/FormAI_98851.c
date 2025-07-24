//FormAI DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    struct sockaddr_in serv_addr;

    // Creating socket file descriptor
    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char message[100];
    while (1) {
        printf("Enter a message: ");
        fgets(message, 100, stdin);

        // Send message to the server
        int bytes_sent = send(sock_fd, message, strlen(message), 0);
        if (bytes_sent == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // Receive message from the server
        char buffer[1024] = {0};
        int bytes_received = recv(sock_fd, buffer, 1024, 0);
        if (bytes_received == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("Server response: %s", buffer);
    }

    return 0;
}