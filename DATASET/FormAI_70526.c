//FormAI DATASET v1.0 Category: Email Client ; Style: rigorous
/* 
 * A C Email Client that utilizes SMTP protocol for sending emails
 * 
 * Author: John Doe 
 * Email: john@gmail.com
 * 
 * This program is licensed under the MIT License.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

void send_email(int socket, char* from, char* to, char* subject, char* body) {
    char buffer[MAX_BUFFER];
    int read_size;

    // Send HELO command
    sprintf(buffer, "HELO myclient.com\r\n");
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);

    // Send email body
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(socket, buffer, strlen(buffer), 0);
    read(socket, buffer, MAX_BUFFER);
}

int main(int argc, char const *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *from = "example@gmail.com";
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "Hello, this is a test email.";

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Configure server address
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect");
        return 1;
    }

    // Send email
    send_email(socket_desc, from, to, subject, body);

    return 0;
}