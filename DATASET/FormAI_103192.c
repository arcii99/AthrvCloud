//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scientific
/**
 * @file ftp_client.c
 * @brief A simple FTP client program to download files from an FTP server.
 * @author [Your Name]
 * @date [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SERVER_ADDR "127.0.0.1" // FTP server address
#define SERVER_PORT 21 // FTP server port number
#define MAX_SIZE 1024 // Maximum buffer size for file download

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create socket
    if (sockfd < 0) { // Check for errors
        perror("Socket creation failed.\n");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr)); // Clear the address struct

    // Fill in the address information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT); // Convert to network byte order
    inet_pton(AF_INET, SERVER_ADDR, &servaddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { // Check for errors
        perror("Connection failed.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];

    // Read welcome message
    int bytes_read = read(sockfd, buffer, MAX_SIZE);
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    buffer[bytes_read] = '\0'; // Append null terminator
    printf("%s", buffer);

    // Login with username and password
    char user[MAX_SIZE], pass[MAX_SIZE];
    printf("Username:");
    scanf("%s", user);
    write(sockfd, user, strlen(user));
    bytes_read = read(sockfd, buffer, MAX_SIZE);
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    buffer[bytes_read] = '\0'; // Append null terminator
    printf("%s", buffer);
    printf("Password:");
    scanf("%s", pass);
    write(sockfd, pass, strlen(pass));
    bytes_read = read(sockfd, buffer, MAX_SIZE);
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    buffer[bytes_read] = '\0'; // Append null terminator
    printf("%s", buffer);

    // Change to passive mode
    write(sockfd, "PASV", strlen("PASV"));
    bytes_read = read(sockfd, buffer, MAX_SIZE);
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    buffer[bytes_read] = '\0'; // Append null terminator
    printf("%s", buffer);
    char* token = strtok(buffer, "(),"); // Parse response
    token = strtok(NULL, "(),");
    token = strtok(NULL, "(),");
    token = strtok(NULL, "(),");
    token = strtok(NULL, "(),");
    int port = atoi(token); // Get port number

    // Connect to data port
    int sockfd_data = socket(AF_INET, SOCK_STREAM, 0); // Create socket
    if (sockfd_data < 0) { // Check for errors
        perror("Socket creation failed.\n");
        exit(1);
    }
    struct sockaddr_in servaddr_data;
    memset(&servaddr_data, 0, sizeof(servaddr_data)); // Clear the address struct
    servaddr_data.sin_family = AF_INET;
    servaddr_data.sin_port = htons(port);
    inet_pton(AF_INET, SERVER_ADDR, &servaddr_data.sin_addr);
    if (connect(sockfd_data, (struct sockaddr*)&servaddr_data, sizeof(servaddr_data)) != 0) { // Check for errors
        perror("Data connection failed.\n");
        exit(1);
    }

    // Download file
    char filename[MAX_SIZE];
    printf("Enter filename:");
    scanf("%s", filename);
    char command[MAX_SIZE];
    sprintf(command, "RETR %s", filename);
    write(sockfd, command, strlen(command));
    bytes_read = read(sockfd, buffer, MAX_SIZE);
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    buffer[bytes_read] = '\0'; // Append null terminator
    printf("%s", buffer);

    FILE* fp = fopen(filename, "w");
    if (fp == NULL) { // Check for errors
        perror("Failed to open file for writing.\n");
        exit(1);
    }
    while ((bytes_read = read(sockfd_data, buffer, MAX_SIZE)) > 0) { // Read data from server
        fwrite(buffer, 1, bytes_read, fp);
    }
    if (bytes_read < 0) { // Check for errors
        perror("Failed to read from server.\n");
        exit(1);
    }
    fclose(fp); // Close file
    printf("File downloaded successfully.\n");

    // Close sockets and exit
    close(sockfd_data);
    close(sockfd);
    return 0;
}