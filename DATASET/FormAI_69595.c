//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int socketfd, bytes_received;
    struct sockaddr_in server_address;
    char buffer[MAX_LENGTH] = {0};

    // Create socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    // Set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110);

    if (inet_pton(AF_INET, "pop3.example.com", &server_address.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(socketfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Connection failed");
    }

    // Receive message from server
    if ((bytes_received = read(socketfd, buffer, MAX_LENGTH)) < 0) {
        error("Read error");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send username
    printf("Username: ");
    char username[MAX_LENGTH];
    fgets(username, MAX_LENGTH, stdin);
    snprintf(buffer, MAX_LENGTH, "USER %s", username);
    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        error("Send error");
    }

    // Receive message from server
    if ((bytes_received = read(socketfd, buffer, MAX_LENGTH)) < 0) {
        error("Read error");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send password
    printf("Password: ");
    char password[MAX_LENGTH];
    fgets(password, MAX_LENGTH, stdin);
    snprintf(buffer, MAX_LENGTH, "PASS %s", password);
    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        error("Send error");
    }

    // Receive message from server
    if ((bytes_received = read(socketfd, buffer, MAX_LENGTH)) < 0) {
        error("Read error");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Quit connection
    snprintf(buffer, MAX_LENGTH, "QUIT");
    if (send(socketfd, buffer, strlen(buffer), 0) < 0) {
        error("Send error");
    }

    // Receive message from server
    if ((bytes_received = read(socketfd, buffer, MAX_LENGTH)) < 0) {
        error("Read error");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(socketfd);

    return 0;
}