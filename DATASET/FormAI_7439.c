//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {

    // Establishing a socket connection
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];
    client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Verifying the connection
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending HELO command
    char helo_command[] = "HELO example.com\r\n";
    send(client_socket, helo_command, strlen(helo_command), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending MAIL FROM command
    char mail_from_command[] = "MAIL FROM:<sender@example.com>\r\n";
    send(client_socket, mail_from_command, strlen(mail_from_command), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending RCPT TO command
    char rcpt_to_command[] = "RCPT TO:<recipient@example.com>\r\n";
    send(client_socket, rcpt_to_command, strlen(rcpt_to_command), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending DATA command
    char data_command[] = "DATA\r\n";
    send(client_socket, data_command, strlen(data_command), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending mail content
    char mail_content[] = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: SMTP Client Example\r\n\r\nThis is an example email sent from a SMTP client program.\r\n.\r\n";
    send(client_socket, mail_content, strlen(mail_content), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Sending QUIT command
    char quit_command[] = "QUIT\r\n";
    send(client_socket, quit_command, strlen(quit_command), 0);
    memset(buffer, '0', sizeof(buffer));
    recv(client_socket, buffer, 1024, 0);
    printf("%s\n", buffer);

    // Closing the socket connection
    close(client_socket);
    return 0;
}