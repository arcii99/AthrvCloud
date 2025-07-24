//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    // Defining variables
    int socket_desc;
    struct sockaddr_in server;
    char server_reply[4000];
    char *message, *HELO, *MAIL_FROM, *RCPT_TO, *DATA, *QUIT;
    char *body;

    // Creating socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    // Setting up server information
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connecting to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connection Error");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // SMTP Commands
    HELO = "HELO google.com\r\n";
    MAIL_FROM = "MAIL FROM:<example@gmail.com>\r\n";
    RCPT_TO = "RCPT TO:<recipient@example.com>\r\n";
    DATA = "DATA\r\n";

    // Sending HELO Command
    if (send(socket_desc, HELO, strlen(HELO), 0) < 0)
    {
        puts("Send HELO failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Sending MAIL FROM Command
    if (send(socket_desc, MAIL_FROM, strlen(MAIL_FROM), 0) < 0)
    {
        puts("Send MAIL FROM failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Sending RCPT TO Command
    if (send(socket_desc, RCPT_TO, strlen(RCPT_TO), 0) < 0)
    {
        puts("Send RCPT TO failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Sending DATA Command
    if (send(socket_desc, DATA, strlen(DATA), 0) < 0)
    {
        puts("Send DATA failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Sending Email Body
    body = "Subject: Test Email\r\n\r\nThis is a test email\r\n.\r\n";
    if (send(socket_desc, body, strlen(body), 0) < 0)
    {
        puts("Send email body failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Sending QUIT Command
    QUIT = "QUIT\r\n";
    if (send(socket_desc, QUIT, strlen(QUIT), 0) < 0)
    {
        puts("Send QUIT failed");
        return 1;
    }

    // Receive server response
    if (recv(socket_desc, server_reply, 4000, 0) < 0)
    {
        puts("recv failed");
    }

    // Display server response
    printf("%s\n", server_reply);

    // Closing socket
    close(socket_desc);

    return 0;
}