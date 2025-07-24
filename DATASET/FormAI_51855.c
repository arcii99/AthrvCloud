//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define SERVER_PORT 25

int main(int argc, char *argv[])
{
    int sock_fd;
    struct sockaddr_in server_addr;
    char message[1024];

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection failed");
        return 1;
    }

    // Send email content to server
    strcpy(message, "HELO localhost\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "MAIL FROM: <example@domain.com>\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "RCPT TO: <recipient@domain.com>\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "DATA\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "Subject: Test Email\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "This is a test email sent from a cyberpunk SMTP client.\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, ".\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    strcpy(message, "QUIT\r\n");
    send(sock_fd, message, strlen(message), 0);
    memset(message, 0, sizeof(message));

    // Close socket
    close(sock_fd);

    printf("Email sent successfully!\n");
    return 0;
}