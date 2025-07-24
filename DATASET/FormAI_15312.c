//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *server_addr = argv[1];
    const char *user = argv[2];
    const char *pass = argv[3];
    
    int client_sock;
    struct sockaddr_in server_addr_info;
    
    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error\n");
        exit(EXIT_FAILURE);
    }
    
    server_addr_info.sin_family = AF_INET;
    server_addr_info.sin_port = htons(993);
    
    if (inet_pton(AF_INET, server_addr, &server_addr_info.sin_addr) <= 0) {
        perror("Invalid or unsupported address\n");
        exit(EXIT_FAILURE);
    }
    
    if (connect(client_sock, (struct sockaddr *)&server_addr_info, sizeof(server_addr_info)) < 0) {
        perror("Connection error\n");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUF_SIZE];
    memset(&buffer, 0, BUF_SIZE);
    ssize_t num_bytes_rcvd;
    
    // Send username and receive response
    sprintf(buffer, "a001 LOGIN %s %s\n", user, pass);
    send(client_sock, buffer, strlen(buffer), 0);
    num_bytes_rcvd = recv(client_sock, buffer, BUF_SIZE, 0);
    if (num_bytes_rcvd < 0) {
        perror("Error receiving data\n");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);
    memset(&buffer, 0, BUF_SIZE);
    
    // List inbox messages
    sprintf(buffer, "a002 LIST \"\" *\n");
    send(client_sock, buffer, strlen(buffer), 0);
    num_bytes_rcvd = recv(client_sock, buffer, BUF_SIZE, 0);
    if (num_bytes_rcvd < 0) {
        perror("Error receiving data\n");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);
    memset(&buffer, 0, BUF_SIZE);
    
    // Logout and close connection
    sprintf(buffer, "a003 LOGOUT\n");
    send(client_sock, buffer, strlen(buffer), 0);
    num_bytes_rcvd = recv(client_sock, buffer, BUF_SIZE, 0);
    if (num_bytes_rcvd < 0) {
        perror("Error receiving data\n");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", buffer);
    memset(&buffer, 0, BUF_SIZE);
    
    close(client_sock);
    exit(EXIT_SUCCESS);
}