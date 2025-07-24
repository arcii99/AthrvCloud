//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Error: Invalid address.\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", buffer);

    write(sockfd, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));

    printf("Result: %s\n", buffer);

    close(sockfd);
    return 0;
}