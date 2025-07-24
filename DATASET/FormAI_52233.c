//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int ftpClient();

int main(int argc, char *argv[]) {

    printf("Starting FTP client...\n");

    ftpClient();

    printf("Exiting FTP client...\n");

    return 0;
}

// Connect to the FTP server and process user commands
int ftpClient() {

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server information
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(21); // FTP server port

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    char buffer[BUFFER_SIZE] = {0};

    // Wait for the server response
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server response");
        return -1;
    }

    printf("Connected to the server\n");
    printf("Response: %s", buffer);

    // Username
    printf("Enter username: ");
    char username[BUFFER_SIZE];
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    // Send username to the server
    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("Error sending username to server");
        return -1;
    }

    // Wait for the server response
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server response");
        return -1;
    }

    printf("Server response: %s", buffer);

    // Password
    printf("Enter password: ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    // Send password to the server
    if (send(sockfd, password, strlen(password), 0) < 0) {
        perror("Error sending password to server");
        return -1;
    }

    // Wait for the server response
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving server response");
        return -1;
    }

    printf("Server response: %s", buffer);

    while (1) {
        printf("\nFTP client > ");
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        char command[BUFFER_SIZE];
        char arg[BUFFER_SIZE];
        memset(command, 0, sizeof(command));
        memset(arg, 0, sizeof(arg));

        // Parse the user input
        int i = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            command[i] = input[i];
            ++i;
        }

        if (input[i] == ' ')
            ++i;

        int j = 0;
        while (input[i] != '\0') {
            arg[j] = input[i];
            ++i;
            ++j;
        }

        // Send command to the server
        if (send(sockfd, input, strlen(input), 0) < 0) {
            perror("Error sending command to server");
            return -1;
        }

        // Wait for the server response
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving server response");
            return -1;
        }

        printf("Server response: %s", buffer);

        if (strncmp(command, "quit", 4) == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}