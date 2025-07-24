//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXBUF 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    uint16_t portnum = 143; // IMAP4 default port number
    struct sockaddr_in servaddr;
    struct hostent *he;
    char buffer[MAXBUF];
    char username[MAXBUF], password[MAXBUF];
    char *responsecode, *nextarg, *command;

    // get server hostname and login credentials
    if (argc != 4) {
        printf("usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }
    char *hostname = argv[1];
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    // get IP address of server
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: invalid hostname.\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket.\n");
        exit(1);
    }

    // initialize server address/port struct
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portnum);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: could not connect to server.\n");
        exit(1);
    }

    // receive server greeting
    n = recv(sockfd, buffer, MAXBUF - 1, 0);
    if (n < 0) {
        printf("Error: could not receive response from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // send login command
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        printf("Error: could not send login command to server.\n");
        exit(1);
    }

    // receive response to login command
    n = recv(sockfd, buffer, MAXBUF - 1, 0);
    if (n < 0) {
        printf("Error: could not receive response from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // send SELECT command to choose inbox
    sprintf(buffer, "SELECT INBOX\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        printf("Error: could not send SELECT command to server.\n");
        exit(1);
    }

    // receive response to SELECT command
    n = recv(sockfd, buffer, MAXBUF - 1, 0);
    if (n < 0) {
        printf("Error: could not receive response from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // send FETCH command to retrieve first message
    sprintf(buffer, "FETCH 1 BODY.PEEK[]\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        printf("Error: could not send FETCH command to server.\n");
        exit(1);
    }

    // receive response to FETCH command
    n = recv(sockfd, buffer, MAXBUF - 1, 0);
    if (n < 0) {
        printf("Error: could not receive response from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // parse response to FETCH command to extract message content
    responsecode = strtok(buffer, "\r\n");
    while (responsecode != NULL) {
        if (strstr(responsecode, "BODY[]") != NULL) {
            nextarg = strtok(NULL, "\r\n");
            while (nextarg != NULL && strncmp(nextarg, ") ", 2) != 0) {
                printf("%s\n", nextarg);
                nextarg = strtok(NULL, "\r\n");
            }
        }
        responsecode = strtok(NULL, "\r\n");
    }

    // send QUIT command to disconnect from server
    sprintf(buffer, "LOGOUT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        printf("Error: could not send QUIT command to server.\n");
        exit(1);
    }

    // receive response to QUIT command
    n = recv(sockfd, buffer, MAXBUF - 1, 0);
    if (n < 0) {
        printf("Error: could not receive response from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}