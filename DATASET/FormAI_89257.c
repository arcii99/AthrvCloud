//FormAI DATASET v1.0 Category: Image Editor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, n, opt=1;
    char buffer[255];

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if(sockfd < 0) {
        error("Error opening socket!");
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Error on binding!");
    }

    listen(sockfd, 5);

    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);

        if(newsockfd < 0) {
            error("Error on accepting!");
        }

        int pid = fork();

        if(pid < 0) {
            error("Error on forking!");
        }

        if(pid == 0) {
            close(sockfd);

            while(1) {
                memset(buffer, '\0', 255);
                n = recv(newsockfd, buffer, 255, 0);

                if(n < 0) {
                    error("Error reading from socket!");
                }

                printf("Client: %s\n", buffer);
                printf("Server: ");

                memset(buffer, '\0', 255);
                fgets(buffer, 255, stdin);

                n = send(newsockfd, buffer, strlen(buffer), 0);

                if(n < 0) {
                    error("Error writing to socket!");
                }

                int i = strncmp("Bye", buffer, 3);

                if(i == 0) {
                    break;
                }
            }
            close(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}