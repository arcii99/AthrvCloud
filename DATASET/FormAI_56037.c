//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 2048 // Max buffer size for data transfer
#define FTP_PORT 21 // Default FTP port

// Function to handle FTP client commands
void handleUserCommand(int sockfd) {
    char command[MAX_BUF_SIZE];
    char response[MAX_BUF_SIZE];

    while (1) {
        printf("\nEnter a command: ");
        fgets(command, MAX_BUF_SIZE, stdin);

        if (send(sockfd, command, strlen(command), 0) < 0) { // send command to server
            printf("Error: Failed to send command to server\n");
            continue;
        }

        if (recv(sockfd, response, MAX_BUF_SIZE, 0) < 0) { // receive response from server
            printf("Error: Failed to receive response from server\n");
            continue;
        } else {
            printf("%s", response);
        }

        // Logout if user issues "QUIT" command
        if (strcasecmp(command, "QUIT\n") == 0) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUF_SIZE];

    if (argc < 2) {
        printf("Usage: ./ftpclient <server_address>\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return -1;
    }

    printf("Socket created successfully\n");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(FTP_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error: Failed to connect to server\n");
        return -1;
    }

    printf("Connected to server %s:%d\n", argv[1], FTP_PORT);

    if (recv(sockfd, buffer, MAX_BUF_SIZE, 0) < 0) { // read welcome message from server
        printf("Error: Failed to receive welcome message from server\n");
        return -1;
    }

    printf("%s", buffer);

    // Login if FTP server is ready
    if (strncmp(buffer, "220", 3) == 0) {
        printf("Enter username: ");
        fgets(buffer, MAX_BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0); // send username to server

        printf("Enter password: ");
        fgets(buffer, MAX_BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0); // send password to server

        if (recv(sockfd, buffer, MAX_BUF_SIZE, 0) < 0) { // read login response from server
            printf("Error: Failed to receive login response from server\n");
            return -1;
        }

        printf("%s", buffer);

        // Handle user commands after successful login
        if (strncmp(buffer, "230", 3) == 0) {
            handleUserCommand(sockfd);
        }
    }

    close(sockfd);

    return 0;
}