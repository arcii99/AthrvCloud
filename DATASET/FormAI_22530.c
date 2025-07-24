//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define SMTP_SERVER "smtp.server.com"
#define SMTP_PORT 25

int main(int argc, char *argv[]) {

    // Check if user has input the recipient email and message
    if (argc < 3) {
        printf("Usage: %s recipient@example.com \"message body\"\n", argv[0]);
        return 0;
    }

    // Establish a TCP connection with the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        return 0;
    }

    // Receive response from SMTP server
    char server_response[MAX_LINE];
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send HELO command to SMTP server
    char helo_command[MAX_LINE];
    sprintf(helo_command, "HELO %s\r\n", SMTP_SERVER);
    if (send(sock, helo_command, strlen(helo_command), 0) < 0) {
        perror("Send error");
        return 0;
    }

    // Receive response from SMTP server
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send MAIL FROM command to SMTP server
    char *mail_from = "MAIL FROM:<paranoidstyle@gmail.com>\r\n";
    if (send(sock, mail_from, strlen(mail_from), 0) < 0) {
        perror("Send error");
        return 0;
    }

    // Receive response from SMTP server
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send RCPT TO command to SMTP server
    char rcpt_to[MAX_LINE];
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", argv[1]);
    if (send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("Send error");
        return 0;
    }

    // Receive response from SMTP server
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send DATA command to SMTP server
    char *data = "DATA\r\n";
    if (send(sock, data, strlen(data), 0) < 0) {
        perror("Send error");
        return 0;
    }

    // Receive response from SMTP server
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send message to SMTP server
    char message[MAX_LINE];
    sprintf(message, "To: <%s>\r\nFrom: <paranoidstyle@gmail.com>\r\nSubject: A Paranoid-Style Message\r\n\r\n%s\r\n.\r\n", argv[1], argv[2]);
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Send error");
        return 0;
    }

    // Receive response from SMTP server
    if (recv(sock, server_response, MAX_LINE, 0) < 0) {
        perror("Receive error");
        return 0;
    }
    printf("%s", server_response);

    // Send QUIT command to SMTP server and close connection
    char *quit = "QUIT\r\n";
    if (send(sock, quit, strlen(quit), 0) < 0) {
        perror("Send error");
        return 0;
    }

    close(sock);

    return 0;
}