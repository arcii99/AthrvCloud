//FormAI DATASET v1.0 Category: Socket programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void surrealism(int sockfd)
{
    char buffer[1024];
    int n;

    while (1) {
        bzero(buffer, 1024);
        printf("Enter your dream: ");
        n = 0;
        while ((buffer[n++] = getchar()) != '\n');

        write(sockfd, buffer, strlen(buffer));

        bzero(buffer, 1024);
        read(sockfd, buffer, 1024);
        printf("I received a message from the dreamland: %s", buffer);
    }
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("ERROR: Could not create socket\n");
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("ERROR: Failed to connect to server\n");
        return -1;
    }

    surrealism(sockfd);

    close(sockfd);
    return 0;
}