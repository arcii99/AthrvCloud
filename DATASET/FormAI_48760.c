//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE], user[BUF_SIZE], pass[BUF_SIZE], cmd[BUF_SIZE];
    int bytes_sent, bytes_received;
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr("pop.gmail.com");
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        close(sock);
        exit(1);
    }
    
    // Receive server greeting
    memset(buffer, 0, BUF_SIZE);
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error receiving server greeting\n");
        close(sock);
        exit(1);
    }
    printf("%s", buffer);
    
    // Send the user command
    memset(user, 0, BUF_SIZE);
    printf("Username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';
    sprintf(cmd, "USER %s\r\n", user);
    bytes_sent = send(sock, cmd, strlen(cmd), 0);
    if (bytes_sent < 0) {
        printf("Error sending user command\n");
        close(sock);
        exit(1);
    }
    
    // Receive user response
    memset(buffer, 0, BUF_SIZE);
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error receiving user response\n");
        close(sock);
        exit(1);
    }
    printf("%s", buffer);

    // Send the pass command
    memset(pass, 0, BUF_SIZE);
    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';
    sprintf(cmd, "PASS %s\r\n", pass);
    bytes_sent = send(sock, cmd, strlen(cmd), 0);
    if (bytes_sent < 0) {
        printf("Error sending pass command\n");
        close(sock);
        exit(1);
    }

    // Receive pass response
    memset(buffer, 0, BUF_SIZE);
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error receiving pass response\n");
        close(sock);
        exit(1);
    }
    printf("%s", buffer);

    // Send the list command
    sprintf(cmd, "LIST\r\n");
    bytes_sent = send(sock, cmd, strlen(cmd), 0);
    if (bytes_sent < 0) {
        printf("Error sending list command\n");
        close(sock);
        exit(1);
    }

    // Receive list response
    memset(buffer, 0, BUF_SIZE);
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error receiving list response\n");
        close(sock);
        exit(1);
    }
    printf("%s", buffer);

    // Send the quit command
    sprintf(cmd, "QUIT\r\n");
    bytes_sent = send(sock, cmd, strlen(cmd), 0);
    if (bytes_sent < 0) {
        printf("Error sending quit command\n");
        close(sock);
        exit(1);
    }

    // Receive quit response
    memset(buffer, 0, BUF_SIZE);
    bytes_received = recv(sock, buffer, BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error receiving quit response\n");
        close(sock);
        exit(1);
    }
    printf("%s", buffer);

    // Close the socket
    close(sock);
    return 0;
}