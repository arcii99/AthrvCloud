//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_ip = "127.0.0.1";
    int server_port = 110;

    // Create socket
    int client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if (recv(client_socket, buf, sizeof(buf), 0) == -1) {
        perror("Failed to receive greeting message");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send username
    printf("Username: ");
    char username[BUF_SIZE];
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';   // Remove newline character
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    if (send(client_socket, buf, strlen(buf), 0) == -1) {
        perror("Failed to send username");
        exit(EXIT_FAILURE);
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(client_socket, buf, sizeof(buf), 0) == -1) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send password
    printf("Password: ");
    char password[BUF_SIZE];
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';   // Remove newline character
    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    if (send(client_socket, buf, strlen(buf), 0) == -1) {
        perror("Failed to send password");
        exit(EXIT_FAILURE);
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(client_socket, buf, sizeof(buf), 0) == -1) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // List messages
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(client_socket, buf, strlen(buf), 0) == -1) {
        perror("Failed to list messages");
        exit(EXIT_FAILURE);
    }

    // Receive response
    memset(buf, 0, sizeof(buf));
    if (recv(client_socket, buf, sizeof(buf), 0) == -1) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Disconnect
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(client_socket, buf, strlen(buf), 0) == -1) {
        perror("Failed to send quit command");
        exit(EXIT_FAILURE);
    }
    close(client_socket);

    return 0;
}