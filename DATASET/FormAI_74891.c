//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define MAXLINE 2048
#define POP_PORT 110

int main(int argc, char **argv)
{
    int sockfd, n , logged_in;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE + 1], username[MAXLINE], password[MAXLINE];
    
    if (argc != 2) {
        printf("Usage: %s <server address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to the POP3 server at %s\n", argv[1]);

    while (1) {
        bzero(recvline, sizeof(recvline));
        n = read(sockfd, recvline, MAXLINE);

        if (n < 0) {
            perror("read error");
            exit(1);
        } else if (n == 0) {
            printf("Connection closed by server\n");
            break;
        }

        printf("%s", recvline);

        if (!logged_in && strstr(recvline, "+OK") == recvline) {
            printf("Enter your username: ");
            fgets(username, sizeof(username), stdin);
            username[strlen(username) - 1] = '\0';

            char buf[MAXLINE];
            sprintf(buf, "USER %s\r\n", username);
            write(sockfd, buf, strlen(buf));

            n = read(sockfd, recvline, MAXLINE);
            printf("%s", recvline);

            printf("Enter your password: ");
            fgets(password, sizeof(password), stdin);
            password[strlen(password) - 1] = '\0';

            sprintf(buf, "PASS %s\r\n", password);
            write(sockfd, buf, strlen(buf));

            n = read(sockfd, recvline, MAXLINE);
            printf("%s", recvline);
            
            if (strstr(recvline, "+OK") == recvline) {
                logged_in = 1;
                printf("Welcome %s!\n", username);
            } else {
                printf("Invalid credentials. Please try again.\n");
            }
        }

        if (logged_in) {
            printf("\nEnter a command: ");
            char cmd[MAXLINE];
            fgets(cmd, sizeof(cmd), stdin);
            cmd[strlen(cmd) - 1] = '\0';

            if (strcmp(cmd, "QUIT") == 0) {
                write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
                n = read(sockfd, recvline, MAXLINE);
                printf("%s", recvline);

                if (strstr(recvline, "+OK") == recvline) {
                    printf("Goodbye!\n");
                    break;
                } else {
                    printf("Failed to quit. Please try again.\n");
                }
            } else {
                char buf[MAXLINE];
                sprintf(buf, "%s\r\n", cmd);
                write(sockfd, buf, strlen(buf));

                n = read(sockfd, recvline, MAXLINE);
                printf("%s", recvline);
            }
        }
    }

    close(sockfd);
    exit(0);
}