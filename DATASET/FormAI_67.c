//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    // POP3 settings
    char* pop3_server = "pop3.example.com";
    int pop3_port = 110;
    char* username = "your_username";
    char* password = "your_password";

    // Connect to POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(pop3_port);
    inet_pton(AF_INET, pop3_server, &server_addr.sin_addr);

    int status = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("Error connecting to POP3 server");
        exit(1);
    }

    // Receive banner message
    char banner[BUFFER_SIZE];
    status = recv(sockfd, banner, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Error receiving banner message");
        exit(1);
    }
    printf("%s", banner);

    // Send credentials
    char credentials[BUFFER_SIZE];
    sprintf(credentials, "USER %s\r\n", username);
    status = send(sockfd, credentials, strlen(credentials), 0);
    if (status < 0) {
        perror("Error sending username");
        exit(1);
    }

    status = recv(sockfd, credentials, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Error receiving server response");
        exit(1);
    }
    printf("%s", credentials);

    sprintf(credentials, "PASS %s\r\n", password);
    status = send(sockfd, credentials, strlen(credentials), 0);
    if (status < 0) {
        perror("Error sending password");
        exit(1);
    }

    status = recv(sockfd, credentials, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Error receiving server response");
        exit(1);
    }
    printf("%s", credentials);

    // List messages
    char list_command[] = "LIST\r\n";
    status = send(sockfd, list_command, strlen(list_command), 0);
    if (status < 0) {
        perror("Error sending list command");
        exit(1);
    }

    char message_list[BUFFER_SIZE];
    status = recv(sockfd, message_list, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Error receiving message list");
        exit(1);
    }
    printf("%s", message_list);

    // Quit connection
    char quit_command[] = "QUIT\r\n";
    status = send(sockfd, quit_command, strlen(quit_command), 0);
    if (status < 0) {
        perror("Error sending quit command");
        exit(1);
    }

    status = recv(sockfd, quit_command, BUFFER_SIZE, 0);
    if (status < 0) {
        perror("Error receiving quit response");
        exit(1);
    }
    printf("%s", quit_command);

    close(sockfd);
    return 0;
}