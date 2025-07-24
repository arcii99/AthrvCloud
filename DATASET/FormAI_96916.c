//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "mail.example.com"
#define PORT 25

void send_command(int sockfd, char *command, char *response) {
    char buffer[1024];
    int length = strlen(command);

    // Send command to server
    write(sockfd, command, length);

    // Read response from server
    read(sockfd, buffer, 1024);
    strcpy(response, buffer);

    // Print response from server
    printf("%s", response);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char response[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER);
    servaddr.sin_port = htons(PORT);

    // Connect to server
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Initialize connection
    send_command(sockfd, "HELO mail.example.com\r\n", response);

    // Authenticate with server
    send_command(sockfd, "AUTH LOGIN\r\n", response);
    send_command(sockfd, "dXNlcm5hbWU6\r\n", response); // base64 encoded username
    send_command(sockfd, "cGFzc3dvcmQ=\r\n", response); // base64 encoded password

    // Compose email
    send_command(sockfd, "MAIL FROM:<user@example.com>\r\n", response);
    send_command(sockfd, "RCPT TO:<recipient@example.com>\r\n", response);
    send_command(sockfd, "DATA\r\n", response);
    send_command(sockfd, "Subject: Hello World!\r\n\r\n", response);
    send_command(sockfd, "This is an email sent from my C email client.\r\n.\r\n", response);

    // Close connection
    send_command(sockfd, "QUIT\r\n", response);
    close(sockfd);

    return 0;
}