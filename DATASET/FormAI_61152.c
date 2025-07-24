//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 993

struct imap_user {
    char *username;
    char *password;
    char *server;
};

int main() {
    // Create a socket for communication with the IMAP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
 
    // Set up the address of the IMAP server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
 
    // Connect to the IMAP server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
 
    // Log in to the IMAP server
    struct imap_user user;
    user.username = "example@gmail.com";
    user.password = "password123";
 
    char buffer[1024];
    sprintf(buffer, "A001 LOGIN %s %s\r\n", user.username, user.password);
    send(sock, buffer, strlen(buffer), 0);
 
    // Receive the server's response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
 
    // Select the inbox
    sprintf(buffer, "A002 SELECT INBOX\r\n");
    send(sock, buffer, strlen(buffer), 0);
 
    // Receive the server's response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
 
    // Log out and close the connection
    sprintf(buffer, "A003 LOGOUT\r\n");
    send(sock, buffer, strlen(buffer), 0);
 
    // Receive the server's response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
 
    close(sock);
    return 0;
}