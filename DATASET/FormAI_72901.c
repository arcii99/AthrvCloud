//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number and buffer size
#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a socket for connecting to the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create the socket");
        exit(1);
    }
    
    // Set up the address of the FTP server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) < 0) {
        perror("Failed to convert the address");
        exit(1);
    }
    
    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to the server");
        exit(1);
    }
    
    // Login to the FTP server
    char username[] = "USERNAME";
    char password[] = "PASSWORD";
    char buffer[BUFFER_SIZE];
    ssize_t n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive welcome message");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive user acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive password acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    
    // Navigate to the desired directory
    char dir[] = "/path/to/directory/";
    sprintf(buffer, "CWD %s\r\n", dir);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive directory acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    
    // Download a file from the FTP server
    char filename[] = "FILE.txt";
    sprintf(buffer, "TYPE I\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive type acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    sprintf(buffer, "SIZE %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive size acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    sprintf(buffer, "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);
    FILE *file = fopen(filename, "wb");
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, file);
    }
    fclose(file);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Failed to receive transfer acknowledgement");
        exit(1);
    }
    printf("FTP Server: %s\n", buffer);
    
    // Close the socket and exit
    close(sockfd);
    return 0;
}