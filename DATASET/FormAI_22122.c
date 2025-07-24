//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int sock_desc;
    struct sockaddr_in server;
    char message[2000] , server_reply[5000];

    //Create socket
    sock_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (sock_desc == -1)
    {
        printf("Could not create socket");
    }

    memset(&server,0,sizeof(server));
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 25 );

    //Connect to remote server
    if (connect(sock_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    printf("Connected to SMTP server\n");

    //Receive the initial welcome message from SMTP server
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Initial server reply : %s\n", server_reply);

    //Send EHLO command to initiate SMTP conversation
    sprintf(message, "EHLO myclient\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply to EHLO command
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply to EHLO command : %s\n", server_reply);

    //Send MAIL FROM command to start sending email
    sprintf(message, "MAIL FROM: <sender@example.com>\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply to MAIL FROM command
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply to MAIL FROM command : %s\n", server_reply);

    //Send RCPT TO command to specify recipient
    sprintf(message, "RCPT TO: <recipient@example.com>\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply to RCPT TO command
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply to RCPT TO command : %s\n", server_reply);

    //Send DATA command to start sending email content
    sprintf(message, "DATA\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply to DATA command
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply to DATA command : %s\n", server_reply);

    //Send email content
    sprintf(message, "From: <sender@example.com>\r\nTo: <recipient@example.com>\r\nSubject: SMTP email example\r\n\r\nHello, this is an example email sent via SMTP client\r\n.\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply after sending email content
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply after sending email content : %s\n", server_reply);

    //Send QUIT command to end SMTP conversation
    sprintf(message, "QUIT\r\n");
    if(send(sock_desc, message, strlen(message), 0) < 0)
    {
        printf("send failed\n");
        return 1;
    }

    //Receive server reply after QUIT command
    if(recv(sock_desc, server_reply, 5000, 0) < 0)
    {
        printf("recv failed\n");
    }
    printf("Server reply after QUIT command : %s\n", server_reply);

    return 0;
}