//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    int sock;
    char buffer[1024];

    // create and connect to SMTP server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SMTP_SERVER);
    server.sin_port = htons(SMTP_PORT);
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // receive greeting message from server
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send HELO command
    char HELOcmd[50] = "HELO smtp.example.com\r\n";
    send(sock, HELOcmd, strlen(HELOcmd), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send MAIL FROM command
    char MAILcmd[50] = "MAIL FROM: <sender@example.com>\r\n";
    send(sock, MAILcmd, strlen(MAILcmd), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send RCPT TO command
    char RCPTcmd[50] = "RCPT TO: <recipient@example.com>\r\n";
    send(sock, RCPTcmd, strlen(RCPTcmd), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send DATA command
    char DATAcmd[10] = "DATA\r\n";
    send(sock, DATAcmd, strlen(DATAcmd), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send email message
    char message[200] = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nHello World!\r\n.\r\n";
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // send QUIT command
    char QUITcmd[10] = "QUIT\r\n";
    send(sock, QUITcmd, strlen(QUITcmd), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}