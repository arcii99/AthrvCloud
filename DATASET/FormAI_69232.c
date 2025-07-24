//FormAI DATASET v1.0 Category: Socket programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock_fd, val_read;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Setting server connection details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Making a connection with the server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send and receive data
    while(1) {
        printf("Enter message you want to send (Type 'exit' to terminate the connection): ");
        fgets(message, 1024, stdin);
        message[strcspn(message, "\n")] = 0;

        if(strcmp(message, "exit") == 0) {
            printf("Closing Connection...\n");
            close(sock_fd);
            return 0;
        }

        if(send(sock_fd, message, strlen(message), 0) < 0) {
            printf("\nSend Failed \n");
            return -1;
        }

        val_read = read(sock_fd, message, 1024);
        printf("Server message: %s\n", message);
    }

    return 0;
}