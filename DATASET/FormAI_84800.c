//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_LEN 1000
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 25

int main() {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.");
        return 1;
    }

    // Prepare server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed.");
        return 1;
    }

    // Receive initial server response
    char response[MAX_MESSAGE_LEN];
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response from server.");
        return 1;
    }
    printf("%s\n", response);

    // Send HELO command
    char helo[MAX_MESSAGE_LEN];
    sprintf(helo, "HELO %s\r\n", SERVER_ADDR);
    if (send(sock, helo, strlen(helo), 0) < 0) {
        printf("Error sending HELO command.");
        return 1;
    }

    // Receive HELO server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to HELO command.");
        return 1;
    }
    printf("%s\n", response);

    // Send MAIL FROM command
    char mail[MAX_MESSAGE_LEN];
    sprintf(mail, "MAIL FROM: <user@domain.com>\r\n");
    if (send(sock, mail, strlen(mail), 0) < 0) {
        printf("Error sending MAIL FROM command.");
        return 1;
    }

    // Receive MAIL FROM server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to MAIL FROM command.");
        return 1;
    }

    printf("%s\n", response);

    // Send RCPT TO command
    char rcpt[MAX_MESSAGE_LEN];
    sprintf(rcpt, "RCPT TO: <recipient@domain.com>\r\n");
    if (send(sock, rcpt, strlen(rcpt), 0) < 0) {
        printf("Error sending RCPT TO command.");
        return 1;
    }

    // Receive RCPT TO server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to RCPT TO command.");
        return 1;
    }

    printf("%s\n", response);

    // Send DATA command
    char data[MAX_MESSAGE_LEN];
    sprintf(data, "DATA\r\n");
    if (send(sock, data, strlen(data), 0) < 0) {
        printf("Error sending DATA command.");
        return 1;
    }

    // Receive DATA server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to DATA command.");
        return 1;
    }

    printf("%s\n", response);

    // Send message body
    char message[MAX_MESSAGE_LEN];
    sprintf(message, "From: <user@domain.com>\r\nTo: <recipient@domain.com>\r\nSubject: Test\r\n\r\nHello world!\r\n.\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error sending message body.");
        return 1;
    }

    // Receive message body server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to message body.");
        return 1;
    }

    printf("%s\n", response);

    // Send QUIT command
    char quit[MAX_MESSAGE_LEN];
    sprintf(quit, "QUIT\r\n");
    if (send(sock, quit, strlen(quit), 0) < 0) {
        printf("Error sending QUIT command.");
        return 1;
    }

    // Receive QUIT server response
    if (recv(sock, response, MAX_MESSAGE_LEN, 0) < 0) {
        printf("Error while receiving response to QUIT command.");
        return 1;
    }

    printf("%s\n", response);

    close(sock);
    return 0;
}