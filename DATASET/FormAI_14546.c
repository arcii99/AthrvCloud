//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define PORT 143

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buff[BUF_SIZE];
    int n, len;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection to server failed\n");
        exit(0);
    }

    // receive greeting message
    memset(buff, 0, sizeof(buff));
    n = read(sockfd, buff, BUF_SIZE);
    if (n == -1) {
        printf("Error receiving greeting message\n");
        exit(0);
    }

    printf("%s", buff);

    // login
    char username[BUF_SIZE], password[BUF_SIZE];
    printf("Enter username: ");
    fgets(username, BUF_SIZE, stdin);
    printf("Enter password: ");
    fgets(password, BUF_SIZE, stdin);

    char login_cmd[BUF_SIZE];
    snprintf(login_cmd, BUF_SIZE, "LOGIN %s %s\r\n", username, password);
    len = strlen(login_cmd);
    if (send(sockfd, login_cmd, len, 0) != len) {
        printf("Error sending login command\n");
        exit(0);
    }

    // receive login response
    memset(buff, 0, sizeof(buff));
    n = read(sockfd, buff, BUF_SIZE);
    if (n == -1) {
        printf("Error receiving login response\n");
        exit(0);
    }

    printf("%s", buff);

    // list emails
    if (send(sockfd, "LIST\r\n", 6, 0) != 6) {
        printf("Error sending list command\n");
        exit(0);
    }

    // receive email list
    memset(buff, 0, sizeof(buff));
    n = read(sockfd, buff, BUF_SIZE);
    if (n == -1) {
        printf("Error receiving email list\n");
        exit(0);
    }

    printf("%s", buff);

    // quit
    if (send(sockfd, "LOGOUT\r\n", 8, 0) != 8) {
        printf("Error sending logout command\n");
        exit(0);
    }

    shutdown(sockfd, SHUT_RDWR);

    return 0;
}