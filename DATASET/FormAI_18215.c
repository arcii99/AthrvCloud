//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void communicate(int sockfd)
{
    char client_message[100];
    while(1)
    {
        memset(client_message, 0, sizeof(client_message));
        int read_size = read(sockfd, client_message, sizeof(client_message));
        if (read_size <= 0) break;
        printf("Client: %s\n", client_message);
        printf("Sherlock Holmes: I see, could you please tell me more details?\n");
        char server_message[100];
        fgets(server_message, sizeof(server_message), stdin);
        write(sockfd, server_message, strlen(server_message));
    }
}

int main()
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    // create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1)
    {
        printf("Server socket could not be created.\n");
        return -1;
    }
    printf("Server socket created.\n");
    // bind socket to port 8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        printf("Socket could not be bound to port.\n");
        return -1;
    }
    printf("Socket bound to port %d.\n", PORT);
    // listen for incoming connections
    if (listen(server_sockfd, 1) == -1)
    {
        printf("Could not start listening for incoming connections.\n");
        return -1;
    }
    printf("Listening for incoming connections.\n");
    // accept client connection
    client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_len);
    if (client_sockfd == -1)
    {
        printf("Could not accept incoming connection.\n");
        return -1;
    }
    printf("Connection accepted.\n");
    // communicate with client
    communicate(client_sockfd);
    // close sockets
    close(client_sockfd);
    close(server_sockfd);
    return 0;
}