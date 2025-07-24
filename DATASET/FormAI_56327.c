//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define HOSTNAME "imap.gmail.com"
#define PORT "993"

int main() {
    int sockfd, numbytes;
    char buf[BUF_SIZE], username[BUF_SIZE], password[BUF_SIZE], email_status[BUF_SIZE];
    struct addrinfo hints, *res;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get address information for the server
    if (getaddrinfo(HOSTNAME, PORT, &hints, &res) != 0) {
        printf("getaddrinfo() failed\n");
        return 1;
    }

    // create the socket
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        printf("socket() failed\n");
        return 1;
    }

    // connect to the IMAP server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        printf("connect() failed\n");
        return 1;
    }
    
    // receive the server greeting
    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        printf("recv() failed\n");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // send the username
    printf("Username: ");
    fgets(username, BUF_SIZE, stdin);
    strip_newline(username);
    sprintf(buf, "1 LOGIN %s\r\n", username);
    send(sockfd, buf, strlen(buf), 0);
    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        printf("recv() failed\n");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // send the password
    printf("Password: ");
    fgets(password, BUF_SIZE, stdin);
    strip_newline(password);
    sprintf(buf, "2 LOGIN %s %s\r\n", username, password);
    send(sockfd, buf, strlen(buf), 0);
    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        printf("recv() failed\n");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // check for a successful login
    if (strstr(buf, "OK LOGIN Completed") == NULL) {
        printf("Login failed\n");
        return 1;
    }

    // send command to check email status
    sprintf(buf, "3 STATUS INBOX (MESSAGES UNSEEN)\r\n");
    send(sockfd, buf, strlen(buf), 0);
    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        printf("recv() failed\n");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);
    strcpy(email_status, buf);

    // close the connection
    sprintf(buf, "4 LOGOUT\r\n");
    send(sockfd, buf, strlen(buf), 0);
    close(sockfd);

    return 0;
}

void strip_newline(char *str) {
    int len = strlen(str)-1;
    if (str[len] == '\n') {
        str[len] = '\0';
    }
}