//FormAI DATASET v1.0 Category: Socket programming ; Style: surrealist
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 5555
#define BUF_SIZE 256

int main(int argc, char *argv[])
{
    int sockfd, connfd;
    char buffer[BUF_SIZE];
    struct sockaddr_in servaddr, clientaddr;
    socklen_t len;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("Socket bind failed");
        return 1;
    }

    if (listen(sockfd, 5) != 0) {
        perror("Socket listen failed");
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        len = sizeof(clientaddr);
        connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &len);
        if (connfd == -1) {
            perror("Socket accept failed");
            continue;
        }

        inet_ntop(AF_INET, &(clientaddr.sin_addr), buffer, BUF_SIZE);
        printf("New client connected from %s:%d\n", buffer, ntohs(clientaddr.sin_port));
        
        n = read(connfd, buffer, BUF_SIZE);
        while (n > 0) {
            buffer[n] = '\0';
            printf("Received message: %s", buffer);
            write(connfd, buffer, n);
            n = read(connfd, buffer, BUF_SIZE);
        }
        
        printf("Client disconnected\n");
        close(connfd);
    }

    return 0;
}