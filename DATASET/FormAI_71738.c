//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "smtp.gmail.com" // The SMTP mail server to use
#define PORT 587 // SMTP server port
#define MAX_MSG_SIZE 1024 // Maximum message size

int main()
{
    int sock = 0;
    struct sockaddr_in server_addr;
    char message[MAX_MSG_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error \n");
        return -1;
    }

    // Set server_addr to zeros
    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection Failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send HELO message
    sprintf(message, "HELO example.com\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send RCPT TO message
    sprintf(message, "RCPT TO: <receiver@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send message content
    sprintf(message, "From: <sender@example.com>\r\n"
                      "To: <receiver@example.com>\r\n"
                      "Subject: Test Subject\r\n"
                      "\r\n"
                      "This is a test message from my SMTP client.\r\n"
                      ".\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed \n");
        return -1;
    }

    // Read server response
    if (recv(sock, message, MAX_MSG_SIZE, 0) < 0)
    {
        printf("Receive failed \n");
        return -1;
    }

    printf("Server response: %s \n", message);

    // Close socket
    close(sock);

    return 0;
}