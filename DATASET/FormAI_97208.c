//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define POP3_PORT 110

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE];
    struct sockaddr_in servaddr;

    if (argc < 2)
        printf("Usage: %s <Server IP Address>\n", argv[0]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("Socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        perror("inet_pton error");

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        perror("Connect error");

    // read the welcome message sent from server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    printf("%s", recvline);

    // login to the server by sending the username and password
    char username[MAXLINE], password[MAXLINE];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char userCmd[MAXLINE], passCmd[MAXLINE];
    sprintf(userCmd, "USER %s\r\n", username);
    sprintf(passCmd, "PASS %s\r\n", password);

    write(sockfd, userCmd, strlen(userCmd));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    printf("%s", recvline);

    write(sockfd, passCmd, strlen(passCmd));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    printf("%s", recvline);

    // retrieve the list of emails and their associated information
    write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    printf("%s", recvline);

    while (1) {
        char input[MAXLINE];
        int emailNum;
        printf("Enter the number of the email to read (or -1 to quit): ");
        scanf("%s", input);
        emailNum = atoi(input);

        if (emailNum == -1)
            break;

        // retrieve the specified email
        char retrCmd[MAXLINE];
        sprintf(retrCmd, "RETR %d\r\n", emailNum);
        write(sockfd, retrCmd, strlen(retrCmd));

        // read in the data of the email
        char buffer[MAXLINE];
        FILE *fp = fopen("email.txt", "w");
        while ((n = read(sockfd, buffer, MAXLINE)) > 0) {
            buffer[n] = 0;
            fprintf(fp, "%s", buffer);
            if (strstr(buffer, "\r\n.\r\n") != NULL)
                break;
        }
        fclose(fp);
        printf("Email saved to file: email.txt\n");
    }

    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    printf("%s", recvline);

    close(sockfd);
    return 0;
 }