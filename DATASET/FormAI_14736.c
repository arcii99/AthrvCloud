//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: innovative
/*
* FTP Client Example Program
* A simple FTP client that can upload and download files
* Written by: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: ./ftpclient <ip_address> <username> <password>\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error: Failed to create socket.\n");
    }

    // Server info
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        error("Error: Invalid IP address.\n");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        error("Error: Failed to connect to server.\n");
    }

    // Authenticate
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\r\n", argv[2]);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        error("Error: Failed to send username.\n");
    }

    memset(buffer, 0, sizeof(buffer));

    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        error("Error: Failed to receive response.\n");
    }

    if (strncmp(buffer, "331", 3) != 0) {
        error("Error: Invalid response to username.\n");
    }

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\r\n", argv[3]);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        error("Error: Failed to send password.\n");
    }

    memset(buffer, 0, sizeof(buffer));

    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        error("Error: Failed to receive response.\n");
    }

    if (strncmp(buffer, "230", 3) != 0) {
        error("Error: Invalid response to password.\n");
    }

    // Download file
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RETR %s\r\n", "file.txt");

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        error("Error: Failed to send retr command.\n");
    }

    FILE *file = fopen("file.txt", "wb");
    if (file == NULL) {
        error("Error: Failed to create file.\n");
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);

        if (bytes_recv == -1) {
            error("Error: Failed to receive data.\n");
        } else if (bytes_recv == 0) {
            break;
        } else {
            fwrite(buffer, sizeof(char), bytes_recv, file);
        }
    }

    fclose(file);

    // Upload file
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "STOR %s\r\n", "file.txt");

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        error("Error: Failed to send stor command.\n");
    }

    file = fopen("file.txt", "rb");
    if (file == NULL) {
        error("Error: Failed to open file.\n");
    }

    while (!feof(file)) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);

        if (bytes_read < sizeof(buffer)) {
            if (ferror(file)) {
                error("Error: Failed to read file.\n");
            }
        }

        int bytes_sent = send(sockfd, buffer, bytes_read, 0);

        if (bytes_sent == -1) {
            error("Error: Failed to send data.\n");
        } else if (bytes_sent != bytes_read) {
            error("Error: Failed to send all data.\n");
        }
    }

    fclose(file);

    // Close connection
    close(sockfd);

    return EXIT_SUCCESS;
}