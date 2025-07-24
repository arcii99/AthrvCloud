//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
    char server[30] = "mail.example.com"; // SMTP server address
    char sender[30] = "sender@example.com";
    char receiver[30] = "receiver@example.com";
    char subject[50] = "Hello, this is a SMTP client example";
    char message[500] = "This is the message body.";
    int sockfd, port;
    struct sockaddr_in dest;

    port = 25; // SMTP port number

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd<0){
        perror("Error creating socket");
        exit(1);
    }

    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    inet_pton(AF_INET, server, &dest.sin_addr.s_addr);

    if(connect(sockfd, (struct sockaddr *)&dest, sizeof(dest))<0){
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending HELO command to the server
    char helo[50] = "HELO example.com\r\n";
    printf("Sending command: %s", helo);
    send(sockfd, helo, strlen(helo), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending MAIL FROM command to the server
    char mailfrom[50];
    memset(mailfrom, 0, sizeof(mailfrom));
    snprintf(mailfrom, sizeof(mailfrom), "MAIL FROM: <%s>\r\n", sender);
    printf("Sending command: %s", mailfrom);
    send(sockfd, mailfrom, strlen(mailfrom), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending RCPT TO command to the server
    char rcptto[50];
    memset(rcptto, 0, sizeof(rcptto));
    snprintf(rcptto, sizeof(rcptto), "RCPT TO: <%s>\r\n", receiver);
    printf("Sending command: %s", rcptto);
    send(sockfd, rcptto, strlen(rcptto), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending DATA command to the server
    char data[50] = "DATA\r\n";
    printf("Sending command: %s", data);
    send(sockfd, data, strlen(data), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending message body to the server
    char msg[550];
    memset(msg, 0, sizeof(msg));
    snprintf(msg, sizeof(msg), "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s\r\n.\r\n", sender, receiver, subject, message);
    printf("Sending message:\n%s", msg);
    send(sockfd, msg, strlen(msg), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Sending QUIT command to the server
    char quit[50] = "QUIT\r\n";
    printf("Sending command: %s", quit);
    send(sockfd, quit, strlen(quit), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}