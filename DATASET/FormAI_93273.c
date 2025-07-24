//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024   // the buffer size for incoming messages
#define PORT 993           // IMAP port

/* function to connect to the server */
int connectToServer(char* serverAddress) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(serverAddress);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection failed...\n");
        exit(0);
    }
    else {
        printf("Connected!\n");
    }
    
    return sockfd;
}

/* function to log in to the server */
void login(int sockfd, char* username, char* password) {
    char buffer[BUFFER_SIZE];
    int n;

    /* send the username */
    sprintf(buffer, "a LOGIN %s %s\r\n", username, password);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));

    /* read the response */
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));
}

/* function to list the mailboxes */
void list(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    /* send the LIST command */
    sprintf(buffer, "a LIST \"\" *\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));

    /* read the response */
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));
}

/* function to select a mailbox */
void selectMailbox(int sockfd, char* mailbox) {
    char buffer[BUFFER_SIZE];
    int n;

    /* send the SELECT command */
    sprintf(buffer, "a SELECT %s\r\n", mailbox);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));

    /* read the response */
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));
}

/* function to fetch the messages */
void fetch(int sockfd, int start, int end) {
    char buffer[BUFFER_SIZE];
    int n;

    /* send the FETCH command */
    sprintf(buffer, "a FETCH %d:%d BODY[]\r\n", start, end);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));

    /* read the response */
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    bzero(buffer, sizeof(buffer));
}

int main() {
    int sockfd;
    char* serverAddress = "127.0.0.1"; // replace with your server's address
    char* username = "example@domain.com"; // replace with your email address
    char* password = "password"; // replace with your password

    /* connect to the server */
    sockfd = connectToServer(serverAddress);

    /* log in to the server */
    login(sockfd, username, password);

    /* list the mailboxes */
    list(sockfd);

    /* select a mailbox */
    selectMailbox(sockfd, "INBOX");

    /* fetch the messages */
    fetch(sockfd, 1, 10);

    /* close the socket */
    close(sockfd);

    return 0;
}