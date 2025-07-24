//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000
#define BACKLOG 5
#define BUFFER_SIZE 256

int main()
{
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, BACKLOG);
    printf("Server started, listening on port %d...\n", PORT);

    while(1) {
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(1) {
            bzero(buffer, BUFFER_SIZE);
            int n = read(new_sockfd, buffer, BUFFER_SIZE-1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            if (n == 0) {
                printf("Connection closed by remote host\n");
                break;
            }
            printf("Received message: %s", buffer);

            n = write(new_sockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
        close(new_sockfd);
        printf("Connection closed\n");
    }
    close(sockfd);
    return 0;
}