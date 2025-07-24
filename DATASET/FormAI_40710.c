//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <errno.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 1024
#define ERROR -1

int proxySocket, clientSocket, remoteSocket;

void handle(int sig)
{
    close(proxySocket);
    close(clientSocket);
    close(remoteSocket);
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, handle);

    int serverPort;
    struct sockaddr_in serverAddr, clientAddr, remoteAddr;
    socklen_t clientAddrSize = sizeof(clientAddr), remoteAddrSize = sizeof(remoteAddr);

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <server-port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    serverPort = atoi(argv[1]);

    if ((proxySocket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PROXY_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxySocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == ERROR)
    {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(proxySocket, 5) == ERROR)
    {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Proxy server listening on port %d\n", PROXY_PORT);

    while (1)
    {
        if ((clientSocket = accept(proxySocket, (struct sockaddr *)&clientAddr, &clientAddrSize)) == ERROR)
        {
            perror("accept");
            continue;
        }

        char clientIp[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIp, INET_ADDRSTRLEN);

        printf("Connection from %s:%d\n", clientIp, ntohs(clientAddr.sin_port));

        if ((remoteSocket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
        {
            perror("socket");
            close(clientSocket);
            continue;
        }

        if (connect(remoteSocket, (struct sockaddr *)&remoteAddr, remoteAddrSize) == ERROR)
        {
            perror("connect");
            close(clientSocket);
            close(remoteSocket);
            continue;
        }

        char request[BUFFER_SIZE];
        int bytes = recv(clientSocket, request, BUFFER_SIZE, 0);

        if (bytes == ERROR)
        {
            perror("recv");
            close(clientSocket);
            close(remoteSocket);
            continue;
        }

        request[bytes] = '\0';
        printf("%s\n", request);

        char *p = strstr(request, "Host:");
        char *q = strstr(p, "\r\n");

        if (p == NULL || q == NULL)
        {
            close(clientSocket);
            close(remoteSocket);
            continue;
        }

        int hostLength = q - p - strlen("Host: ");
        char host[hostLength + 1];
        memset(host, 0, sizeof(host));
        strncpy(host, p + strlen("Host: "), hostLength);

        printf("Host: %s\n", host);

        struct hostent *he = gethostbyname(host);

        if (he == NULL)
        {
            perror("gethostbyname");
            close(clientSocket);
            close(remoteSocket);
            continue;
        }

        remoteAddr.sin_family = AF_INET;
        remoteAddr.sin_port = htons(serverPort);
        memcpy(&remoteAddr.sin_addr, he->h_addr_list[0], he->h_length);

        if (send(remoteSocket, request, bytes, 0) == ERROR)
        {
            perror("send");
            close(clientSocket);
            close(remoteSocket);
            continue;
        }

        char response[BUFFER_SIZE];

        while (1)
        {
            bytes = recv(remoteSocket, response, BUFFER_SIZE, 0);

            if (bytes == ERROR)
            {
                perror("recv");
                close(clientSocket);
                close(remoteSocket);
                continue;
            }

            if (bytes == 0)
            {
                break;
            }

            if (send(clientSocket, response, bytes, 0) == ERROR)
            {
                perror("send");
                close(clientSocket);
                close(remoteSocket);
                continue;
            }
        }

        close(clientSocket);
        close(remoteSocket);
        printf("Connection closed\n");
    }

    return EXIT_SUCCESS;
}