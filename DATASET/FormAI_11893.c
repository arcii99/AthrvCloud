//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
/* 
 * SMTP Client using sockets
 * 
 * Author: Claude Shannon
 * Date: January 1, 1948
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Socket Connection Information
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        exit(1);
    }

    // Receive initial response
    char server_response[1024];
    recv(sock, &server_response, sizeof(server_response), 0);

    // Send HELO command
    char helo_command[50] = "HELO example.com\r\n";
    send(sock, helo_command, sizeof(helo_command), 0);

    // Receive response
    recv(sock, &server_response, sizeof(server_response), 0);

    // Send MAIL FROM command
    char mail_command[100] = "MAIL FROM:<user@example.com>\r\n";
    send(sock, mail_command, sizeof(mail_command), 0);

    // Receive response
    recv(sock, &server_response, sizeof(server_response), 0);

    // Send RCPT TO command
    char rcpt_command[100] = "RCPT TO:<recipient@example.com>\r\n";
    send(sock, rcpt_command, sizeof(rcpt_command), 0);

    // Receive response
    recv(sock, &server_response, sizeof(server_response), 0);

    // Send DATA command
    char data_command[10] = "DATA\r\n";
    send(sock, data_command, sizeof(data_command), 0);

    // Receive response
    recv(sock, &server_response, sizeof(server_response), 0);

    // Send email message
    char email_body[500] = "From: user@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email.";
    send(sock, email_body, sizeof(email_body), 0);

    // Send QUIT command
    char quit_command[10] = "QUIT\r\n";
    send(sock, quit_command, sizeof(quit_command), 0);

    // Receive response
    recv(sock, &server_response, sizeof(server_response), 0);

    // Close the socket
    close(sock);

    return 0;
}