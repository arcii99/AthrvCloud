//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

//server parameters
#define SERVER "mail.server.com"
#define PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[1024];

    //create a socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    //set server parameters
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    //connect to server
    if (connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr)) < 0) {
        printf("Connect failed");
        return 1;
    }

    //send HELO message
    sprintf(message, "HELO %s\r\n", SERVER);
    send(sock, message, strlen(message), 0);

    //send MAIL FROM message
    sprintf(message, "MAIL FROM: <%s>\r\n", "youremail@server.com");
    send(sock, message, strlen(message), 0);

    //send RCPT TO message
    sprintf(message, "RCPT TO: <%s>\r\n", "recipient@server.com");
    send(sock, message, strlen(message), 0);

    //send DATA message
    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);

    //send message body
    sprintf(message, "From: <%s>\r\nSubject: My Grateful Email\r\n\r\nHello recipient, I just wanted to thank you for being amazing! Sincerely, your friend.\r\n.\r\n", "youremail@server.com");
    send(sock, message, strlen(message), 0);

    //close connection
    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);
    close(sock);

    return 0;
}