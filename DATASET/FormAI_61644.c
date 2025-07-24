//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1024

void sendCommand(int sockfd, char *command, char *response);

int main(int argc, char *argv[])
{
    int sockfd;
    char buffer[MAXLINE];
    char response[MAXLINE];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);

    if (inet_pton(AF_INET, "smtp.gmail.com", &servaddr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Read the server's greeting message
    if (read(sockfd, buffer, MAXLINE) < 0)
    {
        printf("Error reading from server\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send HELO/EHLO command to start the conversation
    sendCommand(sockfd, "EHLO client\r\n", response);
    printf("%s\n", response);

    // Send MAIL FROM command to specify sender's email address
    sendCommand(sockfd, "MAIL FROM:<sender@gmail.com>\r\n", response);
    printf("%s\n", response);

    // Send RCPT TO command to specify recipient's email address
    sendCommand(sockfd, "RCPT TO:<recipient@gmail.com>\r\n", response);
    printf("%s\n", response);

    // Send DATA command to start email content
    sendCommand(sockfd, "DATA\r\n", response);
    printf("%s\n", response);

    // Send email headers and body
    sendCommand(sockfd, "From: sender@gmail.com\r\n", response);
    sendCommand(sockfd, "To: recipient@gmail.com\r\n", response);
    sendCommand(sockfd, "Subject: SMTP Client Testing\r\n", response);
    sendCommand(sockfd, "Content-Type: text/plain\r\n\r\n", response);
    sendCommand(sockfd, "Hello recipient, this is a test email sent from a minimalist SMTP client.\r\n", response);

    // Send the terminating period character
    sendCommand(sockfd, ".\r\n", response);
    printf("%s\n", response);

    // Send the QUIT command to terminate the conversation
    sendCommand(sockfd, "QUIT\r\n", response);
    printf("%s\n", response);

    close(sockfd);

    return 0;
}

void sendCommand(int sockfd, char *command, char *response)
{
    // Send the command to the server
    if (write(sockfd, command, strlen(command)) < 0)
    {
        printf("Error sending command to server\n");
        exit(EXIT_FAILURE);
    }

    // Read the server's response
    if (read(sockfd, response, MAXLINE) < 0)
    {
        printf("Error reading from server\n");
        exit(EXIT_FAILURE);
    }
}