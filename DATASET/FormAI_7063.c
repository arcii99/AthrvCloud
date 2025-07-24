//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Print usage information.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse server IP address.
    struct in_addr server_ip;
    if (inet_pton(AF_INET, argv[1], &server_ip) == 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Parse server port number.
    int server_port = atoi(argv[2]);
    if (server_port == 0) {
        fprintf(stderr, "Invalid port number: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Initialize socket communication.
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = server_ip;
    server_addr.sin_port = htons(server_port);
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read initial message from server.
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    ssize_t num_bytes = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send user credentials to server.
    printf("Username: ");
    char username[BUFFER_SIZE];
    fgets(username, BUFFER_SIZE, stdin);
    size_t username_len = strlen(username);

    printf("Password: ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    size_t password_len = strlen(password);

    char login_command[username_len + password_len + 15];
    snprintf(login_command, sizeof(login_command), "USER %sPASS %s", username, password);

    if (send(socket_fd, login_command, strlen(login_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read response from server.
    memset(buffer, 0, sizeof(buffer));
    num_bytes = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send command to list all emails.
    if (send(socket_fd, "LIST\n", strlen("LIST\n"), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read response from server.
    memset(buffer, 0, sizeof(buffer));
    num_bytes = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Close socket and exit.
    if (shutdown(socket_fd, SHUT_RDWR) == -1) {
        perror("shutdown");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}