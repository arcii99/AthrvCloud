//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "mail.example.com"
#define PORT 25

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[2000];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created\n");
     
    server.sin_addr.s_addr = inet_addr("192.168.0.23");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // connect to server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connect failed");
        return 1;
    }
    printf("Connected\n");

    // receive greeting message from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Greeting message: %s\n", message);

    // send HELO command to server
    sprintf(message, "HELO %s\r\n", SERVER);
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("HELO sent\n");

    // receive response from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Response: %s\n", message);

    // send MAIL FROM command
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("MAIL FROM sent\n");

    // receive response from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Response: %s\n", message);

    // send RCPT TO command
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("RCPT TO sent\n");

    // receive response from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Response: %s\n", message);

    // send DATA command
    sprintf(message, "DATA\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("DATA sent\n");

    // receive response from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Response: %s\n", message);

    // send mail message
    sprintf(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test\r\n\r\nHello,\r\nThis is a test message.\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("Mail message sent\n");

    // send QUIT command
    sprintf(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("QUIT sent\n");

    // receive response from server
    if(recv(sock, message, 2000, 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Response: %s\n", message);

    printf("Closing socket\n");
    close(sock);
    return 0;
}