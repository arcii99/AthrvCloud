//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define BUFSIZE 4096
#define SERVER_IP "mail.example.com"

int main() {

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (client_socket < 0) {
        printf("Failed to create socket. Error code: %d\n", client_socket);
        return 1;
    }

    // Create the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        printf("Failed to connect to server. Error code: %d\n", client_socket);
        return 1;
    }

    // Get server response
    char server_response[BUFSIZE] = {0};
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send HELO message
    char helo_message[BUFSIZE] = {0};
    sprintf(helo_message, "HELO %s\r\n", SERVER_IP);
    write(client_socket, helo_message, strlen(helo_message));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send MAIL FROM message
    char mail_from[BUFSIZE] = {0};
    sprintf(mail_from, "MAIL FROM: <sender@example.com>\r\n");
    write(client_socket, mail_from, strlen(mail_from));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send RCPT TO message
    char rcpt_to[BUFSIZE] = {0};
    sprintf(rcpt_to, "RCPT TO: <recipient@example.com>\r\n");
    write(client_socket, rcpt_to, strlen(rcpt_to));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send DATA message
    char data[BUFSIZE] = {0};
    sprintf(data, "DATA\r\n");
    write(client_socket, data, strlen(data));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send email message
    char email_body[BUFSIZE] = {0};
    sprintf(email_body, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email message.\r\n.\r\n");
    write(client_socket, email_body, strlen(email_body));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Send QUIT message
    char quit[BUFSIZE] = {0};
    sprintf(quit, "QUIT\r\n");
    write(client_socket, quit, strlen(quit));
    read(client_socket, server_response, BUFSIZE);
    printf("%s", server_response);

    // Close the socket
    close(client_socket);

    printf("Email sent successfully!\n");
    
    return 0;
}