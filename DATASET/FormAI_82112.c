//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP_PROTOCOL 0
#define PORT_NO 8080
#define NET_BUF_SIZE 32

void clearBuf(char* b) {
    int i;
    for (i = 0; i < NET_BUF_SIZE; i++)
        b[i] = '\0';
}

int main() {
    int sockfd, newsockfd, n, len;
    struct sockaddr_in serverAddress, clientAddress;
    char netBuf[NET_BUF_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, IP_PROTOCOL);
    if (sockfd < 0) {
        printf("Socket creation error\n");
        return 1;
    }
    memset(&serverAddress, '\0', sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT_NO);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress))) != 0) {
        printf("Socket binding error\n");
        return 1;
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen error\n");
        return 1;
    }

    len = sizeof(clientAddress);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr*)&clientAddress, &len);
        if (newsockfd < 0) {
            printf("Accept error\n");
            return 1;
        }
        pid_t childpid = fork();
        if (childpid == 0) {
            close(sockfd);
            while (1) {
                clearBuf(netBuf);
                n = read(newsockfd, netBuf, sizeof(netBuf));
                if (n <= 0) {
                    break;
                }
                printf("Client: %s\n", netBuf);
                write(newsockfd, netBuf, sizeof(netBuf));
            }
            close(newsockfd);
            exit(0);
        }
        else {
            close(newsockfd);
        }
    }
    return 0;
}