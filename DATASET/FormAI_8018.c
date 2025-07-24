//FormAI DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 200
#define MAX_THREADS 500
#define TIMEOUT 5

void *scan_port(void *ptr);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <IP_address>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in target_addr;
    pthread_t threads[MAX_THREADS];

    memset((void *)&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Scanning ports for %s...\n", argv[1]);

    for (int i = 0; i < PORT_RANGE; i++)
    {
        target_addr.sin_port = htons(i);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0)
        {
            perror("socket");
            exit(1);
        }

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout)) < 0)
        {
            perror("setsockopt");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0)
        {
            printf("Port %d is open\n", i);
            pthread_create(&threads[i], NULL, scan_port, (void *)&i);
        }
        else
        {
            pthread_create(&threads[i], NULL, scan_port, (void *)&i);
        }

        close(sockfd);
    }

    for (int i = 0; i < PORT_RANGE; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *scan_port(void *ptr)
{
    int port = *(int *)ptr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in target_addr;
    memset((void *)&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    target_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0)
    {
        printf("Port %d is open\n", port);
    }

    close(sockfd);

    pthread_exit(NULL);
}