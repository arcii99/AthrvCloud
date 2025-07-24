//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(25);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Receive greeting message from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send HELO message to server
    strcpy(message, "HELO localhost\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send MAIL FROM message to server
    strcpy(message, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send RCPT TO message to server
    strcpy(message, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send DATA message to server
    strcpy(message, "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send message body to server
    strcpy(message, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test SMTP client message\r\n\r\nThis is a test message sent from a C SMTP client.\r\n.\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Send QUIT message to server
    strcpy(message, "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive response from server
    if (recv(sock, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts(server_reply);

    // Close socket
    close(sock);

    return 0;
}