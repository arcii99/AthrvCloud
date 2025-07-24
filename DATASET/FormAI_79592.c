//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define DEFAULT_PORT 8888
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int serverfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    int port = DEFAULT_PORT;

    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(serverfd, 5) < 0)
    {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor is listening on port %d...\n", port);

    while (1)
    {
        socklen_t client_addr_len = sizeof(client_addr);

        if ((clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0)
        {
            perror("accept error");
            exit(EXIT_FAILURE);
        }

        printf("[INFO] Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[BUFSIZE];

        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, BUFSIZE, "Server time: %H:%M:%S", timeinfo);

        if (send(clientfd, buffer, strlen(buffer), 0) < 0)
        {
            perror("send error");
            exit(EXIT_FAILURE);
        }

        printf("[INFO] Sent message: %s\n", buffer);

        close(clientfd);
    }

    return 0;
}