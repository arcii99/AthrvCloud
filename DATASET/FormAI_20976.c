//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to server successfully\n");

    // telling the server I want to use POP3
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);

    bzero(buffer, BUF_SIZE);
    n = sprintf(buffer, "USER username\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);

    bzero(buffer, BUF_SIZE);
    n = sprintf(buffer, "PASS password\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);

    bzero(buffer, BUF_SIZE);
    n = sprintf(buffer, "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);

    // Reading number of messages
    int num_msgs = 0;
    sscanf(buffer, "+OK %d %*d", &num_msgs);

    if (num_msgs == 0) {
        printf("No new messages\n");
        close(sockfd);
        exit(0);
    } else {
        printf("You have %d new message(s)\n", num_msgs);
    }

    // Retrieve each message
    int msg_num;

    for (msg_num = 1; msg_num <= num_msgs; msg_num++) {
        bzero(buffer, BUF_SIZE);
        n = sprintf(buffer, "RETR %d\r\n", msg_num);
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            error("ERROR writing to socket");
        }

        bzero(buffer, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s", buffer);

        char *end_msg = strstr(buffer, "\r\n.\r\n");

        while (!end_msg) {
            bzero(buffer, BUF_SIZE);
            n = read(sockfd, buffer, BUF_SIZE);

            if (n < 0) {
                error("ERROR reading from socket");
            }

            printf("%s", buffer);
            end_msg = strstr(buffer, "\r\n.\r\n");
        }
    }

    bzero(buffer, BUF_SIZE);
    n = sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}