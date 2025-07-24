//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include<stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char mail_from[BUFFER_SIZE], mail_to[BUFFER_SIZE], subject[BUFFER_SIZE], body[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        return -1;
    }

    // Set server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        return -1;
    }

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send HELO command
    strcat(strcpy(buffer, "HELO localhost\r\n"), "\0");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Get mail from, to, subject, and body
    printf("Enter mail from: ");
    scanf("%s", mail_from);
    printf("Enter mail to: ");
    scanf("%s", mail_to);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter body: ");
    scanf("%s", body);

    // Send MAIL FROM command
    strcat(strcpy(buffer, "MAIL FROM:<"), mail_from);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send RCPT TO command
    strcat(strcpy(buffer, "RCPT TO:<"), mail_to);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send DATA command
    strcat(strcpy(buffer, "DATA\r\n"), "\0");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send mail from, to, subject, and body
    strcat(strcpy(buffer, "From: <"), mail_from);
    strcat(buffer, ">\r\n");
    strcat(strcpy(buffer, "To: <"), mail_to);
    strcat(buffer, ">\r\n");
    strcat(strcpy(buffer, "Subject: "), subject);
    strcat(buffer, "\r\n\r\n");
    strcat(strcpy(buffer, body), "\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send QUIT command
    strcat(strcpy(buffer, "QUIT\r\n"), "\0");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read and print server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}