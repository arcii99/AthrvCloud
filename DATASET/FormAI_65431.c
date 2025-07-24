//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 1024

int main()
{
    int sock_desc;
    struct sockaddr_in server_addr;
    char message[MAX];

    /* Create socket */
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1)
    {
        printf("Could not create socket!");
        return 1;
    }

    /* Set server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(25);

    /* Connect to server */
    if(connect(sock_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Could not connect to server!");
        return 1;
    }

    /* Receive server response */
    char response[MAX];
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send HELO command */
    snprintf(message, MAX, "HELO example.com\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send HELO command!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send MAIL FROM command */
    snprintf(message, MAX, "MAIL FROM:<example@example.com>\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send MAIL FROM command!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send RCPT TO command */
    snprintf(message, MAX, "RCPT TO:<recipient@example.com>\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send RCPT TO command!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send DATA command */
    snprintf(message, MAX, "DATA\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send DATA command!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send email content */
    snprintf(message, MAX, "Subject: Example Email\r\n\r\nThis is the body of the email.\r\n.\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send email content!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Send QUIT command */
    snprintf(message, MAX, "QUIT\r\n");
    if(send(sock_desc, message, strlen(message), 0) == -1)
    {
        printf("Could not send QUIT command!");
        return 1;
    }

    /* Receive server response */
    if(recv(sock_desc, response, MAX, 0) == -1)
    {
        printf("Could not receive server response!");
        return 1;
    }
    printf("%s\n", response);

    /* Close socket */
    close(sock_desc);
    return 0;
}