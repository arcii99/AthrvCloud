//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surprised
// Wow! Can you believe it? We are about to build a FTP client in C!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// This function will establish a connection with the FTP server using IPv4 and returns the socket file descriptor
int establish_connection(char *ip_address, int port) {
    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Oops! Socket file descriptor couldn't be created successfully.\n");
        exit(0);
    }
    printf("Amazing! Socket file descriptor created successfully.\n");

    // Assigning server information
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
        printf("Oops! Invalid IP address or address not supported.\n");
        exit(0);
    }
    printf("Great! Server IP successfully assigned.\n");

    // Establishing connection
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Oops! Connection couldn't be established with the FTP server.\n");
        exit(0);
    }
    printf("Amazing! Connected with the FTP server successfully.\n");

    return sockfd;
}

int main() {
    printf("Unbelievable! We are building a FTP client in C.\n");

    // Establishing connection with the FTP server
    int sockfd = establish_connection("127.0.0.1", 21);

    // Receiving welcome message from FTP server
    char buffer[BUFFER_SIZE] = {0};
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Oops! Couldn't receive welcome message from FTP server.\n");
        exit(0);
    }
    printf("Yay! Received welcome message from FTP server: %s\n", buffer);

    // Logging in as anonymous user
    if (send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0) < 0) {
        printf("Oops! User command couldn't be sent to FTP server.\n");
        exit(0);
    }
    printf("Great! User command sent to FTP server successfully.\n");
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Oops! Couldn't receive response from FTP server.\n");
        exit(0);
    }
    printf("Amazing! Received response from FTP server: %s\n", buffer);

    // Logging in with password
    if (send(sockfd, "PASS \r\n", strlen("PASS \r\n"), 0) < 0) {
        printf("Oops! Password command couldn't be sent to FTP server.\n");
        exit(0);
    }
    printf("Great! Password command sent to FTP server successfully.\n");
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Oops! Couldn't receive response from FTP server.\n");
        exit(0);
    }
    printf("Amazing! Received response from FTP server: %s\n", buffer);

    // Retrieving file list
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        printf("Oops! LIST command couldn't be sent to FTP server.\n");
        exit(0);
    }
    printf("Great! LIST command sent to FTP server successfully.\n");
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Oops! Couldn't receive response from FTP server.\n");
        exit(0);
    }
    printf("Yay! Received file list from FTP server: %s\n", buffer);

    // Logging out from FTP server
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        printf("Oops! QUIT command couldn't be sent to FTP server.\n");
        exit(0);
    }
    printf("Great! QUIT command sent to FTP server successfully.\n");
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Oops! Couldn't receive response from FTP server.\n");
        exit(0);
    }
    printf("Amazing! Received response from FTP server: %s\n", buffer);

    // Closing connection with FTP server
    close(sockfd);
    printf("Wow! Connection with FTP server closed successfully.\n");

    return 0;
}