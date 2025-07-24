//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 587 // Port for SMTP

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from SMTP client!";
    char buffer[1024] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Setting server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Reading response from server
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending HELO command to server
    char *helo_cmd = "HELO example.com\r\n";
    send(sock, helo_cmd, strlen(helo_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending MAIL FROM command to server
    char *mail_from_cmd = "MAIL FROM:<from@example.com>\r\n";
    send(sock, mail_from_cmd, strlen(mail_from_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending RCPT TO command to server
    char *rcpt_to_cmd = "RCPT TO:<to@example.com>\r\n";
    send(sock, rcpt_to_cmd, strlen(rcpt_to_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending DATA command to server
    char *data_cmd = "DATA\r\n";
    send(sock, data_cmd, strlen(data_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending message to server
    char *message = "From: from@example.com\r\nTo: to@example.com\r\nSubject: SMTP Client Example\r\n\r\nHello from SMTP client!\r\n.\r\n";
    send(sock, message, strlen(message), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Sending QUIT command to server
    char *quit_cmd = "QUIT\r\n";
    send(sock, quit_cmd, strlen(quit_cmd), 0);
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);

    // Closing socket
    close(sock);

    return 0;
}