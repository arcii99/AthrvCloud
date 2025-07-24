//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    // set the server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // send a message to the server
    char* message = "I need food and supplies.";
    send(socket_fd, message, strlen(message), 0);

    // receive a response from the server
    int valread = read(socket_fd, buffer, 1024);
    printf("Server Response: %s\n", buffer);

    // close the socket
    close(socket_fd);
    return 0;
}