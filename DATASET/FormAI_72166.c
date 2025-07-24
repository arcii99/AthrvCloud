//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_RESPONSE_LENGTH 10000

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int read_size;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error\n");
        return 1;
    }
    
    // Receive greeting message
    if (recv(sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("%s\n", response);
    
    // Send user command
    printf("Enter your username: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove newline character
    strcat(command, "\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }
    
    // Receive response to user command
    if (recv(sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("%s\n", response);
    
    // Send password command
    printf("Enter your password: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove newline character
    strcat(command, "\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }
    
    // Receive response to password command
    if (recv(sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("%s\n", response);
    
    // Send list command
    strcpy(command, "LIST\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }
    
    // Receive response to list command
    if (recv(sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("%s\n", response);
    
    // Send quit command
    strcpy(command, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }
    
    // Receive response to quit command
    if (recv(sock, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("%s\n", response);
    
    close(sock);
    return 0;
}