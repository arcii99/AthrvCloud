//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL)
        error("ERROR, no such host");

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to remote server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        printf("FTP> ");

        fgets(buffer, BUFFER_SIZE, stdin);

        if (strncmp(buffer, "QUIT", 4) == 0)
            break;

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0)
            error("ERROR writing to socket");

        memset(buffer, 0, BUFFER_SIZE);

        n = read(sockfd, buffer, BUFFER_SIZE - 1);

        if (n < 0)
            error("ERROR reading from socket");

        printf("%s\n", buffer);
    }

    close(sockfd);

    return 0;
}