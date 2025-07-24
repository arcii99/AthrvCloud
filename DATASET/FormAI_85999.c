//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ftpclient <server-ip-address> <username> <password>\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error: connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char response[BUFFER_SIZE] = {0};
    ssize_t num_bytes;
    // Receive the welcome message from the server
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response); 

    // Login with the username and password
    char command[BUFFER_SIZE] = {0};
    snprintf(command, BUFFER_SIZE, "USER %s\r\n", argv[2]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    memset(command, 0, sizeof(command));
    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", argv[3]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Set Binary mode
    memset(command, 0, sizeof(command));
    snprintf(command, BUFFER_SIZE, "TYPE I\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Change directory to the root
    memset(command, 0, sizeof(command));
    snprintf(command, BUFFER_SIZE, "CWD /\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Retrieve a file
    memset(command, 0, sizeof(command));
    snprintf(command, BUFFER_SIZE, "RETR test.txt\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    FILE *file = fopen("test.txt", "wb");
    if (file == NULL) {
        perror("Error: cannot create file");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    while ((num_bytes = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        fwrite(response, sizeof(char), num_bytes, file);
    }
    fclose(file);

    // Quit the server
    memset(command, 0, sizeof(command));
    snprintf(command, BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error: sending data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    num_bytes = recv(sockfd, response, BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        perror("Error: receiving data failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("%s", response);
  
    // Close the socket
    close(sockfd);
    return 0;
}