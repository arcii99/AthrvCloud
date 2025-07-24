//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2048];

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // replace with desired SMTP server IP address
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // SMTP server port

    // connect to SMTP server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("connect error\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // send HELO message
    message = "HELO example.com\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);
    
    // send MAIL FROM message
    message = "MAIL FROM: <example@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // send RCPT TO message
    message = "RCPT TO: <recipient@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // send DATA message
    message = "DATA\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // send message body
    message = "From: example@example.com\r\nTo: recipient@example.com\r\nSubject: Test\r\n\r\nThis is a test message.\r\n.\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // send QUIT message
    message = "QUIT\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // get server response
    if (recv(socket_desc, server_reply, 2048, 0) < 0) {
        printf("recv failed\n");
        return 1;
    }
    printf("Server response: %s\n", server_reply);

    // close socket
    close(socket_desc);
 
    return 0;
}