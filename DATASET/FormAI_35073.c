//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096
#define POP3_PORT 110

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    
    // Step 1: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }
    
    // Step 2: Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "pop3.example.com", &servaddr.sin_addr);
    
    // Step 3: Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != 0) {
        printf("Failed to connect to server.\n");
        close(sockfd);
        return 1;
    }
    
    // Step 4: Read the server greeting
    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Failed to read from server.\n");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);
    
    // Step 5: Send the username
    printf("Username: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);
    snprintf(buffer, MAX_BUFFER_SIZE, "USER %s", username);
    write(sockfd, buffer, strlen(buffer));
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Failed to read from server.\n");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);
    
    // Step 6: Send the password
    printf("Password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    snprintf(buffer, MAX_BUFFER_SIZE, "PASS %s", password);
    write(sockfd, buffer, strlen(buffer));
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Failed to read from server.\n");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);
    
    // Step 7: Quit
    snprintf(buffer, MAX_BUFFER_SIZE, "QUIT");
    write(sockfd, buffer, strlen(buffer));
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Failed to read from server.\n");
        close(sockfd);
        return 1;
    }
    printf("%s", buffer);
    
    // Step 8: Close the socket
    close(sockfd);
    
    return 0;
}