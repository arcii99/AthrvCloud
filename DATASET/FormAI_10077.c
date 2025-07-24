//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT "8080" // Default server port
#define BACKLOG 10

// Function to handle proxy request
void handle_proxy_request(int client_sockfd)
{
    char buffer[BUFFER_SIZE], req_type[BUFFER_SIZE], req_url[BUFFER_SIZE], req_protocol[BUFFER_SIZE];
    char res_content[BUFFER_SIZE];
    int server_sockfd, bytes_recv, bytes_sent, status_code;
    struct addrinfo hints, *server_info, *p;

    // Receive request from client
    if ((bytes_recv = recv(client_sockfd, buffer, BUFFER_SIZE, 0)) == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Parse HTTP request
    sscanf(buffer, "%s %s %s", req_type, req_url, req_protocol);

    // Open socket to connect to server
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((status_code = getaddrinfo(req_url, SERVER_PORT, &hints, &server_info)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status_code));
        exit(EXIT_FAILURE);
    }

    // Loop through results and connect to the first available server
    for (p = server_info; p != NULL; p = p->ai_next)
    {
        if ((server_sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            perror("socket");
            continue;
        }

        if (connect(server_sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            perror("connect");
            close(server_sockfd);
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        fprintf(stderr, "Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(server_info);

    // Forward request to server
    if ((bytes_sent = send(server_sockfd, buffer, bytes_recv, 0)) == -1)
    {
        perror("send");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Forwarded request:\n%s\n", buffer);

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    while ((bytes_recv = recv(server_sockfd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        // Forward response to client
        if ((bytes_sent = send(client_sockfd, buffer, bytes_recv, 0)) == -1)
        {
            perror("send");
            close(server_sockfd);
            exit(EXIT_FAILURE);
        }

        printf("Forwarded response bytes: %d\n", bytes_sent);

        memset(buffer, 0, BUFFER_SIZE);
    }

    if (bytes_recv < 0)
    {
        perror("recv");
    }

    close(server_sockfd);
}

int main(int argc, char const *argv[])
{
    int sockfd, client_sockfd, status_code;
    struct addrinfo hints, *server_info, *p;
    struct sockaddr_storage client_addr;
    socklen_t addr_size;
    pid_t pid;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status_code = getaddrinfo(NULL, SERVER_PORT, &hints, &server_info)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status_code));
        exit(EXIT_FAILURE);
    }

    // Loop through results and bind to the first available socket
    for (p = server_info; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            perror("socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            perror("bind");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        fprintf(stderr, "Failed to bind to socket.\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(server_info);

    if (listen(sockfd, BACKLOG) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Proxy running on port %s...\n", SERVER_PORT);

    // Handle incoming connections
    while (1)
    {
        addr_size = sizeof client_addr;
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);

        if (client_sockfd == -1)
        {
            perror("accept");
            continue;
        }

        // Fork new process to handle request
        if ((pid = fork()) == 0)
        {
            close(sockfd);
            handle_proxy_request(client_sockfd);
            close(client_sockfd);
            exit(EXIT_SUCCESS);
        }

        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}