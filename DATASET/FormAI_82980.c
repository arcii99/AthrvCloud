//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in server_addr;

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    /* Setup server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(&(server_addr.sin_zero), '\0', 8);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        return 1;
    }

    /* Receive greeting message */
    char buf[BUF_SIZE];
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    /* Send user command */
    char user_cmd[BUF_SIZE];
    sprintf(user_cmd, "USER %s\r\n", argv[2]);
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("send");
        return 1;
    }

    /* Receive response to user command */
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    /* Send pass command */
    char pass_cmd[BUF_SIZE];
    sprintf(pass_cmd, "PASS %s\r\n", argv[3]);
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("send");
        return 1;
    }

    /* Receive response to pass command */
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    /* Send list command to get number of emails */
    if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        return 1;
    }

    /* Receive response to list command */
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    /* Parse number of emails from response */
    int num_emails = -1;
    int i;
    for (i = 0; i < strlen(buf); i++) {
        if (buf[i] == '\n' && i > 0 && buf[i-1] == '.') {
            num_emails = atoi(buf+i+1);
            break;
        }
    }
    printf("You have %d emails\n", num_emails);

    /* Print headers for all emails */
    for (i = 1; i <= num_emails; i++) {
        /* Send retr command for current email */
        char retr_cmd[BUF_SIZE];
        sprintf(retr_cmd, "RETR %d\r\n", i);
        if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1) {
            perror("send");
            return 1;
        }

        /* Receive response to retr command */
        if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
            perror("recv");
            return 1;
        }

        /* Print headers */
        printf("Email %d:\n", i);
        int j;
        for (j = 0; j < strlen(buf); j++) {
            if (buf[j] == '\n') {
                if (j > 0 && buf[j-1] == '\r') {
                    break;
                } else {
                    printf("%c", buf[j]);
                }
            } else {
                printf("%c", buf[j]);
            }
        }
        printf("\n");
    }

    /* Exit */
    close(sockfd);
    return 0;
}