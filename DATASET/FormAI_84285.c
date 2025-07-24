//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21 // Port number of FTP
#define BUFFER_SIZE 1024 // Buffer size
#define MAX_COMMAND_SIZE 100 // Max command size

int main(int argc, char const *argv[]) {
    int sockfd; // File descriptor for socket
    struct sockaddr_in serverAddress; // Server address
    char buffer[BUFFER_SIZE]; // Buffer to store response
    char command[MAX_COMMAND_SIZE]; // Command entered by user
    char username[MAX_COMMAND_SIZE], password[MAX_COMMAND_SIZE]; // FTP Username and Password
    int ret; // Return value for functions
    int fd; // File descriptor for file to be downloaded
    char filename[MAX_COMMAND_SIZE];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // Setting values for server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    ret = inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    if(ret < 0) {
        perror("Error: Cannot convert server address");
        exit(EXIT_FAILURE);
    }

    // Connecting to server
    ret = connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if(ret < 0) {
        perror("Error: Cannot connect to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server on port %d\n", PORT);

    // Reading response from server
    memset(buffer, 0, sizeof(buffer));
    ret = read(sockfd, buffer, sizeof(buffer));
    if(ret < 0) {
        perror("Error: Cannot read server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Requesting username
    printf("Username: ");
    scanf("%s", username);
    snprintf(command, sizeof(command), "USER %s\r\n", username);

    // Sending username to server
    ret = write(sockfd, command, strlen(command));
    if(ret < 0) {
        perror("Error: Cannot send username to server");
        exit(EXIT_FAILURE);
    }

    // Reading response from server
    memset(buffer, 0, sizeof(buffer));
    ret = read(sockfd, buffer, sizeof(buffer));
    if(ret < 0) {
        perror("Error: Cannot read server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Requesting password
    printf("Password: ");
    scanf("%s", password);
    snprintf(command, sizeof(command), "PASS %s\r\n", password);

    // Sending password to server
    ret = write(sockfd, command, strlen(command));
    if(ret < 0) {
        perror("Error: Cannot send password to server");
        exit(EXIT_FAILURE);
    }

    // Reading response from server
    memset(buffer, 0, sizeof(buffer));
    ret = read(sockfd, buffer, sizeof(buffer));
    if(ret < 0) {
        perror("Error: Cannot read server response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Requesting file name
    printf("File name: ");
    scanf("%s", filename);
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);

    // Sending RETR command to server
    ret = write(sockfd, command, strlen(command));
    if(ret < 0) {
        perror("Error: Cannot send RETR command to server");
        exit(EXIT_FAILURE);
    }

    // Opening file to write
    fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if(fd < 0) {
        perror("Error: Cannot open file to write");
        exit(EXIT_FAILURE);
    }

    // Reading response from server and writing it to file
    memset(buffer, 0, sizeof(buffer));
    ret = read(sockfd, buffer, sizeof(buffer));
    if(ret < 0) {
        perror("Error: Cannot read server response");
        exit(EXIT_FAILURE);
    }
    while(ret > 0) {
        write(fd, buffer, ret);
        memset(buffer, 0, sizeof(buffer));
        ret = read(sockfd, buffer, sizeof(buffer));
        if(ret < 0) {
            perror("Error: Cannot read server response");
            exit(EXIT_FAILURE);
        }
    }

    // Closing file and socket
    close(fd);
    close(sockfd);

    printf("File downloaded successfully\n");

    return 0;
}