//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Set up socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server IP and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(587);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    char server_response[BUFFER_SIZE];
    memset(server_response, 0, sizeof(server_response));
    int bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send HELO command to server
    char helo_command[BUFFER_SIZE];
    memset(helo_command, 0, sizeof(helo_command));
    snprintf(helo_command, sizeof(helo_command), "HELO %s\r\n", "localhost");
    if (send(client_socket, helo_command, strlen(helo_command), 0) < 0) {
        printf("Failed to send HELO command\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send MAIL FROM command to server
    char mail_from_command[BUFFER_SIZE];
    memset(mail_from_command, 0, sizeof(mail_from_command));
    snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM:<%s>\r\n", "alice@wonderland.com");
    if (send(client_socket, mail_from_command, strlen(mail_from_command), 0) < 0) {
        printf("Failed to send MAIL FROM command\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send RCPT TO command to server
    char rcpt_to_command[BUFFER_SIZE];
    memset(rcpt_to_command, 0, sizeof(rcpt_to_command));
    snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO:<%s>\r\n", "bob@sandbox.com");
    if (send(client_socket, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        printf("Failed to send RCPT TO command\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send DATA command to server
    char data_command[BUFFER_SIZE];
    memset(data_command, 0, sizeof(data_command));
    snprintf(data_command, sizeof(data_command), "DATA\r\n");
    if (send(client_socket, data_command, strlen(data_command), 0) < 0) {
        printf("Failed to send DATA command\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send message body to server
    char message_body[BUFFER_SIZE];
    memset(message_body, 0, sizeof(message_body));
    snprintf(message_body, sizeof(message_body), "From: alice@wonderland.com\nTo: bob@sandbox.com\nSubject: Hello\n\nThis is a post-apocalyptic message.\r\n.\r\n");
    if (send(client_socket, message_body, strlen(message_body), 0) < 0) {
        printf("Failed to send message body\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Send QUIT command to server
    char quit_command[BUFFER_SIZE];
    memset(quit_command, 0, sizeof(quit_command));
    snprintf(quit_command, sizeof(quit_command), "QUIT\r\n");
    if (send(client_socket, quit_command, strlen(quit_command), 0) < 0) {
        printf("Failed to send QUIT command\n");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    memset(server_response, 0, sizeof(server_response));
    bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Failed to receive server response\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", server_response);

    // Close socket
    close(client_socket);

    return 0;
}