//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

volatile int running = 1;

void sigint_handler(int sig)
{
    running = 0;
}

int main()
{
    signal(SIGINT, sigint_handler);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 1) < 0)
    {
        perror("listen()");
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor started on port %d\n", PORT);

    while (running)
    {
        int connfd = accept(sockfd, NULL, NULL);
        if (connfd < 0)
        {
            perror("accept()");
            exit(EXIT_FAILURE);
        }

        char buf[BUFSIZE];
        ssize_t n = read(connfd, buf, BUFSIZE);
        if (n < 0)
        {
            perror("read()");
            exit(EXIT_FAILURE);
        }
        else if (n == 0)
        {
            close(connfd);
            continue;
        }

        int qos = atoi(buf);
        if (qos < 0 || qos > 10)
        {
            fprintf(stderr, "Invalid QoS value: %d\n", qos);
            close(connfd);
            continue;
        }

        printf("Received QoS value: %d\n", qos);

        if (qos > 7)
        {
            printf("QoS is good\n");
        }
        else if (qos > 4)
        {
            printf("QoS is fair\n");
        }
        else
        {
            printf("QoS is poor\n");
        }

        if (write(connfd, "ACK", 3) < 0)
        {
            perror("write()");
            exit(EXIT_FAILURE);
        }

        close(connfd);
    }

    close(sockfd);

    return 0;
}