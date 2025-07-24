//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("ERROR: Can't open socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("ERROR: No such host.\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR: Can't connect to server.\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, 256);
        printf("Message: ");
        fgets(buffer, 255, stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            printf("ERROR: Can't write to socket.\n");
            exit(1);
        }

        memset(buffer, 0, 256);

        n = read(sockfd, buffer, 255);

        if (n < 0) {
            printf("ERROR: Can't read from socket.\n");
            exit(1);
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}