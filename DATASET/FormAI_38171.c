//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void send_mail(const char *to, const char *from, const char *subject, const char *message, const char *server_address, int server_port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // create server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_address, &servaddr.sin_addr);

    // connect to server
    connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));

    char buffer[1024];

    // receive initial message
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send HELO command
    sprintf(buffer, "HELO %s\r\n", server_address);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send message
    sprintf(buffer, "Subject:%s\r\nFrom:<%s>\r\nTo:<%s>\r\n\r\n%s\r\n.\r\n", subject, from, to, message);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);

    // close socket
    close(sockfd);
}

int main() {
    printf("Hello! This is a SMTP client program.\n");

    // send mail
    send_mail("johndoe@example.com", "janedoe@example.com", "Hello from the SMTP client!", "This is a cheerful email sent by the SMTP client. Yay!", "smtp.example.com", 587);
    
    printf("\nEmail sent successfully! Have a great day!\n");

    return 0;
}