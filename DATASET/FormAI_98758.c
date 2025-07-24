//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 25

int main() {
    char msg[1024] = {'\0'};
    int sock = 0;
    struct sockaddr_in serv_addr;

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection to server failed\n");
        return -1;
    }

    // accept greetings
    read(sock, msg, 1024);
    printf("%s",msg);

    // send email envelope
    char *envelope = "MAIL FROM: <user@gmail.com>\r\nRCPT TO: <receiver@gmail.com>\r\n";
    send(sock, envelope, strlen(envelope), 0);
    read(sock, msg, 1024);
    printf("%s",msg);

    // send email data
    char *data = "DATA\r\nSubject: SMTP Client Test\r\nThis is a test email from SMTP Client.\r\n.\r\n";
    send(sock, data, strlen(data), 0);
    read(sock, msg, 1024);
    printf("%s",msg);

    // send quit command
    char *quit = "QUIT\r\n";
    send(sock, quit, strlen(quit), 0);
    read(sock, msg, 1024);
    printf("%s",msg);

    // close socket
    close(sock);
    return 0;
}