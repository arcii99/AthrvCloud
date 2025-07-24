//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int socket_desc;
    struct sockaddr_in server;
    char *message;
    char server_reply[2000];
     
    //create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
     
    server.sin_addr.s_addr = inet_addr("10.0.2.15"); // IP address of SMTP server
    server.sin_family = AF_INET;
    server.sin_port = htons( 25 ); // port number of SMTP server
    
    //connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    //receive greeting message from SMTP server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
     
    //send HELO message
    message = "HELO example.com\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //send MAIL FROM message
    message = "MAIL FROM:<sender@example.com>\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //send RCPT TO message
    message = "RCPT TO:<recipient@example.com>\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //send DATA message
    message = "DATA\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    
    //send email content
    message = "From: <sender@example.com>\r\n"
              "To: <recipient@example.com>\r\n"
              "Subject: SMTP client program\r\n\r\n"
              "This is a sample email sent from SMTP client program.\r\n"
              ".\r\n"; // ending the email

        if( send(socket_desc , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //send QUIT message
    message = "QUIT\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    memset(server_reply, 0, sizeof(server_reply)); // clear the buffer
    if( recv(socket_desc, server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //close the socket
    close(socket_desc);
    return 0;
}