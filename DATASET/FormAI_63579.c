//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int socket_desc;
    struct sockaddr_in server_addr;
    char *message;
    char server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Server information
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed. Error");
        return 1;
    }

    puts("Connected to SMTP server!");

    // Receive greeting message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send HELO message
    message = "HELO\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("HELO message sent\n");

    // Receive response to HELO message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send MAIL FROM message
    message = "MAIL FROM:<sender@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("MAIL FROM message sent\n");

    // Receive response to MAIL FROM message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send RCPT TO message
    message = "RCPT TO:<recipient@example.com>\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("RCPT TO message sent\n");

    // Receive response to RCPT TO message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send DATA message
    message = "DATA\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("DATA message sent\n");

    // Receive response to DATA message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send email content
    message = "Subject: Test email from C SMTP client\r\nHello!\r\n.\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("Email content sent\n");

    // Receive response to email content
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send QUIT message
    message = "QUIT\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }
    printf("QUIT message sent\n");

    // Receive response to QUIT message
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        perror("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Close socket
    close(socket_desc);

    return 0;
}