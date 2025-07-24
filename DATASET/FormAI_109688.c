//FormAI DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main()
{
    int serv_fd, new_sock, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *hello = "Hello from the server";

    // Creating socket file descriptor
    if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of local addresses
    int opt = 1;
    if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(serv_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addr_len = sizeof(serv_addr);
    if ((new_sock = accept(serv_fd, (struct sockaddr *)&serv_addr, (socklen_t *)&addr_len)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send greeting message to the client
    send(new_sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Read messages from the client and reply with the same message
    while ((valread = read(new_sock, buffer, MAX_BUFFER_SIZE)) > 0)
    {
        printf("Client sent: %s\n", buffer);
        send(new_sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}