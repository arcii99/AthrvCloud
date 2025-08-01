//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXSIZE];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    char user[MAXSIZE];
    char pass[MAXSIZE];
    char filename[MAXSIZE];
    char mode[MAXSIZE];

    printf("Enter username: ");
    scanf("%s", user);
    write(sockfd, user, strlen(user));

    printf("Enter password: ");
    scanf("%s", pass);
    write(sockfd, pass, strlen(pass));

    printf("Enter filename: ");
    scanf("%s", filename);
    write(sockfd, filename, strlen(filename));

    printf("Enter mode: ");
    scanf("%s", mode);
    write(sockfd, mode, strlen(mode));

    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);
    close(sockfd);

    return 0;
}