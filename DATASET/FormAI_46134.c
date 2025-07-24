//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_BUFFER_SIZE 2048

int main(int argc, char** argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving welcome message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send username
    char* user_cmd = "USER username\n";
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("Error sending username");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to username");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send password
    char* pass_cmd = "PASS password\n";
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("Error sending password");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to password");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send command to list directory contents
    char* list_cmd = "LIST\n";
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("Error sending LIST command");
        exit(EXIT_FAILURE);
    }

    // Receive response to list command
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response to LIST command");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Close connection
    close(sockfd);

    return 0;
}