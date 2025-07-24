//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9999
#define BUFSIZE 1024

int sockfd, newsockfd;
socklen_t clilen;
struct sockaddr_in serv_addr, cli_addr;
int n;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void handle_sigint(int sig)
{
    printf("Interrupt received, closing socket...\n");
    close(sockfd);
    exit(0);
}

int main(int argc, char *argv[])
{
    int i, j;
    char buffer[BUFSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error on binding");

    if (listen(sockfd, 5) < 0)
        error("Error on listen");

    signal(SIGINT, handle_sigint);

    printf("QoS Monitor is now running...\n");

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("Error on accept");

    printf("Client connected!\n");

    while (1)
    {
        memset(buffer, 0, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE - 1);
        if (n < 0)
            error("Error reading from socket");

        printf("Received message: %s\n", buffer);

        for (i = 0; i < n; i++)
        {
            if (buffer[i] == ':')
            {
                char request[16];
                char value[16];
                int k = 0;
                for (j = 0; j < i; j++)
                    request[j] = buffer[j];
                request[j] = '\0';
                for (j = i + 1; j < n; j++)
                {
                    if (buffer[j] == '\r' || buffer[j] == '\n')
                        break;
                    value[k++] = buffer[j];
                }
                value[k] = '\0';

                printf("Request: %s, Value: %s\n", request, value);

                if (strcmp(request, "PING") == 0)
                {
                    printf("Sending PONG to client...\n");
                    write(newsockfd, "PONG\r\n", 6);
                }
                else if (strcmp(request, "THROUGHPUT") == 0)
                {
                    printf("Checking network throughput...\n");
                    int x, y;
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (x = 0; x < 100000000; x++);
                    for (y = 0; y < 10; y++)
                        write(newsockfd, "TEST\r\n", 6);
                }
                else if (strcmp(request, "PACKETLOSS") == 0)
                {
                    printf("Checking packet loss...\n");
                    int x;
                    for (x = 0; x < 500000000; x++);
                    for (x = 0; x < 500000000; x++);
                    for (x = 0; x < 500000000; x++);
                    for (x = 0; x < 500000000; x++);
                    for (x = 0; x < 500000000; x++);
                    for (x = 0; x < 100000000; x++);
                    write(newsockfd, "PACKET RECEIVED\r\n", 17);
                }
                else if (strcmp(request, "LATENCY") == 0)
                {
                    printf("Checking network latency...\n");
                    int x, y;
                    for (x = 0; x < 100000000; x++);
                    write(newsockfd, "PING\r\n", 6);
                    sleep(1);
                    for (y = 0; y < 10; y++)
                        write(newsockfd, "TEST\r\n", 6);
                }
                else
                {
                    printf("Unknown Request: %s\n", request);
                }

                break;
            }
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}