//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char message[2000], server_reply[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error");
        return 1;
    }

    // Receive the greeting message from the server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // SMTP commands to send email
    strcpy(message, "HELO myhostname\r\n");
    send(socket_desc, message, strlen(message), 0);

    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    strcpy(message, "MAIL FROM:<sender@example.com>\r\n");
    send(socket_desc, message, strlen(message), 0);
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    strcpy(message, "RCPT TO:<recipient@example.com>\r\n");
    send(socket_desc, message, strlen(message), 0);
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    strcpy(message, "DATA\r\n");
    send(socket_desc, message, strlen(message), 0);
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Email content
    strcpy(message, "From: sender@example.com\r\n");
    strcat(message, "To: recipient@example.com\r\n");
    strcat(message, "Subject: SMTP Test\r\n");
    strcat(message, "\r\n");
    strcat(message, "This is a test email sent using SMTP.\r\n");
    strcat(message, "\r\n.\r\n");
    // Send email content
    send(socket_desc, message, strlen(message), 0);
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Close the socket
    close(socket_desc);
    return 0;
}