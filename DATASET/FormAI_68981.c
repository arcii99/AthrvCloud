//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_mail(int sock, char* msg) {
    char buffer[1024];
    int resp;

    recv(sock, buffer, 1024, 0);
    bzero(buffer, 1024);
    sprintf(buffer, "%s\r\n", msg);
    send(sock, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sock, buffer, 1024, 0);

    if (buffer[0] == '2' && buffer[1] == '5' && buffer[2] == '0') {
        printf("Message sent successfully\n");
    } else {
        printf("Error sending message\n");
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Connected to server\n");

        char buffer[1024];
        int resp;

        recv(sock, buffer, 1024, 0);
        bzero(buffer, 1024);
        sprintf(buffer, "HELO mydomain.com\r\n");
        send(sock, buffer, strlen(buffer), 0);
        bzero(buffer, 1024);
        recv(sock, buffer, 1024, 0);

        printf("Received: %s\n", buffer);

        char *to = "example@gmail.com";
        char *from = "sender@gmail.com";
        char *subject = "This is a test email";
        char *body = "Hello, this is a test email sent using SMTP client";

        char msg[1024];
        sprintf(msg, "MAIL FROM: <%s>\r\n", from);
        send_mail(sock, msg);

        bzero(msg, 1024);
        sprintf(msg, "RCPT TO: <%s>\r\n", to);
        send_mail(sock, msg);

        bzero(msg, 1024);
        sprintf(msg, "DATA\r\n");
        send_mail(sock, msg);

        bzero(msg, 1024);
        sprintf(msg, "Subject: %s\r\n%s\r\n", subject, body);
        send_mail(sock, msg);

        bzero(msg, 1024);
        sprintf(msg, ".");
        send_mail(sock, msg);

        bzero(msg, 1024);
        sprintf(msg, "QUIT\r\n");
        send_mail(sock, msg);
    } else {
        printf("Failed to connect to server\n");
    }
    close(sock);
    return 0;
}