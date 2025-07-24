//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BLOCKED_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    listen(sockfd, 5);

    printf("Listening on port 8080...\n");

    while (1) {
        addr_size = sizeof(serverStorage);
        newsockfd = accept(sockfd, (struct sockaddr *) &serverStorage, &addr_size);
        char *client_ip = inet_ntoa(((struct sockaddr_in *)&serverStorage)->sin_addr);

        if (((struct sockaddr_in *)&serverStorage)->sin_family == AF_INET && ((struct sockaddr_in *)&serverStorage)->sin_port == htons(BLOCKED_PORT)) {
            printf("Blocked traffic from %s on port %d\n", client_ip, BLOCKED_PORT);
            close(newsockfd);
            continue;
        }

        // handle the incoming connection
        // ...

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}