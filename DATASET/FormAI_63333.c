//FormAI DATASET v1.0 Category: Socket programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, cli_sockfd, cli_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    cli_len = sizeof(cli_addr);
    cli_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
    if (cli_sockfd < 0) 
        error("ERROR on accept");

    printf("Connected with client at IP address: %s and port: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (read(cli_sockfd, buffer, sizeof(buffer)) < 0)
            error("ERROR reading from socket");

        printf("Client Message: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            close(cli_sockfd);
            printf("Disconnected from client\n");
            break;
        }

        char server_message[256] = "Received Message";
        if (write(cli_sockfd, server_message, sizeof(server_message)) < 0)
            error("ERROR writing to socket");
    }

    close(sockfd);
    
    return 0;
}