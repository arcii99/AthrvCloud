//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int server_sockfd, client_sockfd;
    socklen_t len;
    struct sockaddr_in server_address, client_address;
    char response[256];
    char request[256];

    // create the socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    memset(server_address.sin_zero, '\0', sizeof server_address.sin_zero);

    // bind the socket to the server address
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // listen for clients
    if (listen(server_sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", ntohs(server_address.sin_port));

    // accept clients
    len = sizeof client_address;
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &len);
    if (client_sockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

    while (1) {
        // receive client request
        if (recv(client_sockfd, request, sizeof(request), 0) == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received request: %s\n", request);

        // send response back to client
        strcpy(response, "Hello, ");
        strcat(response, request);
        if (send(client_sockfd, response, sizeof(response), 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        printf("Sent response: %s\n", response);
    }

    // close the sockets
    close(client_sockfd);
    close(server_sockfd);
    return 0;
}