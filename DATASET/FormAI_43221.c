//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define IP_ADDRESS "127.0.0.1"
#define PORT_NUMBER 21

int main() {
    int socket_fd, connection_fd;
    struct sockaddr_in server_address;
    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);    
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Configure server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    inet_aton(IP_ADDRESS, &server_address.sin_addr);

    // Make connection to server
    connection_fd = connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connection_fd < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive response message from server
    recv(socket_fd, buffer, MAX_SIZE, 0);
    printf("%s", buffer);
    memset(buffer, 0, MAX_SIZE);

    // Send username
    char username[MAX_SIZE];
    printf("Enter username: ");
    fgets(username, MAX_SIZE, stdin);
    send(socket_fd, username, strlen(username), 0);

    // Receive response message from server
    recv(socket_fd, buffer, MAX_SIZE, 0);
    printf("%s", buffer);
    memset(buffer, 0, MAX_SIZE);

    // Send password
    char password[MAX_SIZE];
    printf("Enter password: ");
    fgets(password, MAX_SIZE, stdin);   
    send(socket_fd, password, strlen(password), 0);

    // Receive response message from server
    recv(socket_fd, buffer, MAX_SIZE, 0);
    printf("%s", buffer);
    memset(buffer, 0, MAX_SIZE);

    // Prompt user for command
    while (1) {
        char command[MAX_SIZE];
        printf("Enter command: ");
        fgets(command, MAX_SIZE, stdin);

        // Send command to server
        send(socket_fd, command, strlen(command), 0);

        // Receive response message from server
        recv(socket_fd, buffer, MAX_SIZE, 0);
        printf("%s", buffer);
        memset(buffer, 0, MAX_SIZE);

        // Check if user wants to quit
        if (strncmp(command, "QUIT", 4) == 0) {
            break;
        }
    }

    // Close socket
    close(socket_fd);

    return 0;
}