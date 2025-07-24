//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in server;
    char message[BUFFER_SIZE], server_reply[BUFFER_SIZE];
    char* host = "mail.example.com";
    int port = 25;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("Could not create socket");
        exit(1);
    }

    // Initialize sockaddr_in with server details
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connection failed");
        exit(1);
    }

    // Receive greeting from server
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("Server greeting: %s\n", server_reply);

    // Send HELO message
    sprintf(message, "HELO %s\r\n", host);
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending HELO message failed");
        exit(1);
    }

    // Receive response to HELO message
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("HELO response: %s\n", server_reply);

    // Set mail sender
    sprintf(message, "MAIL FROM:<me@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending MAIL FROM message failed");
        exit(1);
    }

    // Receive response to MAIL FROM message
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("MAIL FROM response: %s\n", server_reply);

    // Set mail recipient
    sprintf(message, "RCPT TO:<you@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending RCPT TO message failed");
        exit(1);
    }

    // Receive response to RCPT TO message
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("RCPT TO response: %s\n", server_reply);

    // Set mail data
    sprintf(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending DATA message failed");
        exit(1);
    }

    // Receive response to DATA message
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("DATA response: %s\n", server_reply);

    // Set mail content
    sprintf(message, "Subject: Test mail\r\n\r\nThis is a test mail.\r\n.\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending mail content failed");
        exit(1);
    }

    // Receive response to mail content
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("Mail content response: %s\n", server_reply);

    // Quit session
    sprintf(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("Sending QUIT message failed");
        exit(1);
    }

    // Receive response to QUIT message
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0)
    {
        perror("Receiving failed");
        exit(1);
    }

    printf("QUIT response: %s\n", server_reply);

    close(sock);

    return 0;
}