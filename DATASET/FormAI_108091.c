//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main() {
    int sockfd = 0, n = 0;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Setup the login credentials and message
    char login[] = "USER <username>\r\n";
    char password[] = "PASS <password>\r\n";
    char from[] = "MAIL FROM: <sender_email>\r\n";
    char to[] = "RCPT TO: <recipient_email>\r\n";
    char data[] = "DATA\r\n";
    char subject[] = "Subject: SMTP Client example\r\n";
    char message[] = "This is an example message sent via SMTP.\r\n.\r\n";

    // Connect to the server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    inet_pton(AF_INET, "<smtp_server_ip_address>", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Read the server's welcome message
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send login credentials
    write(sockfd, login, strlen(login));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    write(sockfd, password, strlen(password));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send sender's email address
    write(sockfd, from, strlen(from));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send recipient's email address
    write(sockfd, to, strlen(to));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Start data transfer
    write(sockfd, data, strlen(data));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send message headers
    write(sockfd, subject, strlen(subject));
    write(sockfd, from, strlen(from));
    write(sockfd, to, strlen(to));
    write(sockfd, "\r\n", strlen("\r\n"));

    // Send message body
    write(sockfd, message, strlen(message));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Quit the session
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    close(sockfd);

    return 0;
}