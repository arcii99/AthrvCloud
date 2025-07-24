//FormAI DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAXBUF 1024

int main(int argc, char *argv[]) {
    int sockfd, recvfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAXBUF];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Enter stock symbol: ");
    bzero(buffer, MAXBUF);
    fgets(buffer, MAXBUF-1, stdin);
    buffer[strlen(buffer)-1]='\0';

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    if ((recvfd = recv(sockfd, buffer, MAXBUF-1, 0)) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[recvfd] = '\0';

    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}