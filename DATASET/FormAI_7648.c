//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_ADDR "smtp.server.com"
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char user_input[BUF_SIZE];
    int read_size, msg_size;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        return 1;
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Read initial server response
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Send HELO command
    sprintf(buf, "HELO smtp.client.com\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send HELO command");
        return 1;
    }

    // Read response from server
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Get sender email address from user
    printf("Enter sender email address: ");
    fgets(user_input, BUF_SIZE, stdin);
    user_input[strcspn(user_input, "\r\n")] = 0; // remove newline character

    // Send MAIL FROM command
    sprintf(buf, "MAIL FROM:<%s>\r\n", user_input);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        return 1;
    }

    // Read response from server
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Get recipient email address from user
    printf("Enter recipient email address: ");
    fgets(user_input, BUF_SIZE, stdin);
    user_input[strcspn(user_input, "\r\n")] = 0; // remove newline character

    // Send RCPT TO command
    sprintf(buf, "RCPT TO:<%s>\r\n", user_input);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send RCPT TO command");
        return 1;
    }

    // Read response from server
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Get message subject from user
    printf("Enter message subject: ");
    fgets(user_input, BUF_SIZE, stdin);
    user_input[strcspn(user_input, "\r\n")] = 0; // remove newline character

    // Get message body from user
    printf("Enter message body (press Enter then Ctrl+D to finish):\n");
    fgets(buf, BUF_SIZE, stdin);

    // Append message headers and construct message
    msg_size = sprintf(buf, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s", user_input, user_input, user_input, buf);

    // Send DATA command
    sprintf(buf, "DATA\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send DATA command");
        return 1;
    }

    // Read response from server
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Send message
    if (send(sock, buf, msg_size, 0) < 0) {
        perror("Failed to send message");
        return 1;
    }

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("Failed to send QUIT command");
        return 1;
    }

    // Read response from server
    read_size = read(sock, buf, BUF_SIZE);
    if (read_size < 0) {
        perror("Failed to read server response");
        return 1;
    }
    printf("%.*s", read_size, buf);

    // Close socket
    close(sock);

    return 0;
}