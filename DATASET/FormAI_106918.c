//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define MAXBUF 1024
#define FTP_PORT 21

// Function to read FTP server response
void read_response(int sockfd) {
    char buffer[MAXBUF];
    ssize_t num_read = read(sockfd, buffer, MAXBUF);
    if (num_read < 0) {
        perror("[ERROR] Failed to read server response.");
        close(sockfd);
        exit(1);
    }
    buffer[num_read] = '\0';
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAXBUF];

    if (argc < 4) {
        printf("[ERROR] Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("[ERROR] Failed to create a socket.");
        exit(1);
    }

    // Resolve IP address of FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 1) {
        perror("[ERROR] Failed to resolve server address.");
        close(sockfd);
        exit(1);
    }

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("[ERROR] Failed to connect to server.");
        close(sockfd);
        exit(1);
    }
    read_response(sockfd);

    // Login as user
    snprintf(buffer, MAXBUF, "USER %s\r\n", argv[2]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("[ERROR] Failed to send user command.");
        close(sockfd);
        exit(1);
    }
    read_response(sockfd);

    // Enter password
    snprintf(buffer, MAXBUF, "PASS %s\r\n", argv[3]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("[ERROR] Failed to send password command.");
        close(sockfd);
        exit(1);
    }
    read_response(sockfd);

    // Switch to binary transfer mode
    if (write(sockfd, "TYPE I\r\n", strlen("TYPE I\r\n")) < 0) {
        perror("[ERROR] Failed to switch to binary mode.");
        close(sockfd);
        exit(1);
    }
    read_response(sockfd);

    // Request a file
    if (write(sockfd, "RETR sample_file.txt\r\n", strlen("RETR sample_file.txt\r\n")) < 0) {
        perror("[ERROR] Failed to initiate file retrieval.");
        close(sockfd);
        exit(1);
    }

    // Read file data
    FILE *fp = fopen("sample_file.txt", "wb");
    if (fp == NULL) {
        perror("[ERROR] Failed to create output file.");
        close(sockfd);
        exit(1);
    }
    while (1) {
        ssize_t num_read = read(sockfd, buffer, MAXBUF);
        if (num_read < 0) {
            perror("[ERROR] Failed to read file data.");
            fclose(fp);
            close(sockfd);
            exit(1);
        }
        if (num_read == 0) {
            break;
        }
        fwrite(buffer, 1, num_read, fp);
    }
    fclose(fp);
    read_response(sockfd);

    // Terminate FTP session
    if (write(sockfd, "QUIT\r\n", strlen("QUIT\r\n")) < 0) {
        perror("[ERROR] Failed to send quit command.");
        close(sockfd);
        exit(1);
    }
    read_response(sockfd);

    // Close socket
    close(sockfd);
    return 0;
}