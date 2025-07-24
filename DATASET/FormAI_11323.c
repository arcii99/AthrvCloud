//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 8080

int main()
{
    int sockfd, newSockfd, status;
    int readBytes;
    char buffer[BUF_SIZE];
    struct sockaddr_in serverAddr, clientAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    status = bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    if(status < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    status = listen(sockfd, 5);
    if(status < 0)
    {
        perror("Error setting up listening socket");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while(1)
    {
        socklen_t clientAddrLen = sizeof(clientAddr);
        newSockfd = accept(sockfd, (struct sockaddr *) &clientAddr, &clientAddrLen);
        if(newSockfd < 0)
        {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        while(1)
        {
            memset(buffer, 0, BUF_SIZE);
            readBytes = recv(newSockfd, buffer, BUF_SIZE, 0);
            if(readBytes < 0)
            {
                perror("Error reading from socket");
                exit(1);
            }
            else if(readBytes == 0)
            {
                printf("Connection closed by client\n");
                break;
            }

            // Quality of Service check
            float sleepTime = (rand() % 50) / 1000.0; // Random sleep time between 0 and 50ms
            struct timespec t;
            t.tv_sec = 0;
            t.tv_nsec = sleepTime * 1000000000; // Convert to nanoseconds
            nanosleep(&t, NULL);

            printf("Received %d bytes from %s:%d\n", readBytes, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        }

        close(newSockfd);
        printf("Connection closed by server\n");
    }

    close(sockfd);

    return 0;
}