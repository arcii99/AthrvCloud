//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

/**
 * This SMTP client program sends an email message to the recipient
 * through the given SMTP server.
 */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <smtp_server> <sender_email_address> <recipient_email_address>\n", argv[0]);
        exit(1);
    }

    // Parse command line arguments
    char *server_addr_str = argv[1];
    char *sender_addr = argv[2];
    char *recipient_addr = argv[3];

    // Create a socket for communication with the SMTP server
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up connection to the SMTP server
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, server_addr_str, &server_addr.sin_addr);

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive initial greeting message from SMTP server
    char greeting_msg[MAX_LINE_SIZE];
    if (recv(sock_fd, greeting_msg, sizeof(greeting_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received greeting from server: %s\n", greeting_msg);

    // Send HELO command to SMTP server
    char helo_cmd[MAX_LINE_SIZE];
    sprintf(helo_cmd, "HELO %s\r\n", server_addr_str);
    if (send(sock_fd, helo_cmd, strlen(helo_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to HELO command from SMTP server
    char response_msg[MAX_LINE_SIZE];
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to HELO command: %s\n", response_msg);

    // Send MAIL FROM command to SMTP server
    char mail_from_cmd[MAX_LINE_SIZE];
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", sender_addr);
    if (send(sock_fd, mail_from_cmd, strlen(mail_from_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to MAIL FROM command from SMTP server
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to MAIL FROM command: %s\n", response_msg);

    // Send RCPT TO command to SMTP server
    char rcpt_to_cmd[MAX_LINE_SIZE];
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", recipient_addr);
    if (send(sock_fd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to RCPT TO command from SMTP server
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to RCPT TO command: %s\n", response_msg);

    // Send DATA command to SMTP server
    char data_cmd[MAX_LINE_SIZE];
    sprintf(data_cmd, "DATA\r\n");
    if (send(sock_fd, data_cmd, strlen(data_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to DATA command from SMTP server
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to DATA command: %s\n", response_msg);

    // Send message body to SMTP server
    char message_body[MAX_LINE_SIZE];
    printf("Enter message body (terminate with a '.' on a line by itself):\n");
    while (fgets(message_body, sizeof(message_body), stdin) != NULL) {
        if (strcmp(message_body, ".\n") == 0) {
            break;
        }
        if (send(sock_fd, message_body, strlen(message_body), 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    // Send end of message indicator to SMTP server
    char end_of_message_cmd[MAX_LINE_SIZE];
    sprintf(end_of_message_cmd, "\r\n.\r\n");
    if (send(sock_fd, end_of_message_cmd, strlen(end_of_message_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to end of message indicator from SMTP server
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to end of message indicator: %s\n", response_msg);

    // Send QUIT command to SMTP server
    char quit_cmd[MAX_LINE_SIZE];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sock_fd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to QUIT command from SMTP server
    if (recv(sock_fd, response_msg, sizeof(response_msg), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received response to QUIT command: %s\n", response_msg);

    // Close connection to SMTP server
    close(sock_fd);

    return 0;
}