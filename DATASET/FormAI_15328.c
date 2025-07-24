//FormAI DATASET v1.0 Category: Socket programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int socket_fd, val_read;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create TCP socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // Set address family, IP and port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    char *hello = "Hello from client!";
    if (send(socket_fd, hello, strlen(hello), 0) < 0)
    {
        perror("Message sending failed");
        exit(EXIT_FAILURE);
    }
    printf("Message sent: %s\n", hello);

    // Receive message from server
    if ((val_read = read(socket_fd, buffer, 1024)) < 0)
    {
        perror("Message receiving failed");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);
    return 0;
}