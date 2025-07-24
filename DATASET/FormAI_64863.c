//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int sock, newSock, valRead;
    struct sockaddr_in servAddr;
    char buffer[1024] = {0};
    char *response = "Hello from server!";

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept a new connection
    int addrLen = sizeof(servAddr);
    if ((newSock = accept(sock, (struct sockaddr *)&servAddr, (socklen_t*)&addrLen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Read data from client
    valRead = read(newSock, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    // Write response to client
    write(newSock, response, strlen(response));

    // Close the sockets
    close(newSock);
    close(sock);

    return 0;
}