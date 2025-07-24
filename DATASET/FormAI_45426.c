//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Read welcome message from server
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Ask for username
    printf("Username: ");
    scanf("%s", buffer);
    write(sockfd, buffer, strlen(buffer));

    // Read response from server
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Ask for password
    printf("Password: ");
    scanf("%s", buffer);
    write(sockfd, buffer, strlen(buffer));

    // Read response from server
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Passive mode
    write(sockfd, "PASV\n", strlen("PASV\n"));

    // Read response from server
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Parse server response to get port number
    char *start = strstr(buffer, "(");
    char *end = strstr(buffer, ")");
    char *port_string = strtok(start+1, ",");
    int port = atoi(port_string) * 256;
    port_string = strtok(NULL, ",");
    port += atoi(port_string);

    // Connect to data socket
    close(sockfd);
    sockfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Ask for file name
    printf("File Name: ");
    scanf("%s", filename);

    // Send download command
    char cmd[BUFFER_SIZE] = "RETR ";
    strcat(cmd, filename);
    strcat(cmd, "\n");

    write(sockfd, cmd, strlen(cmd));

    // Read response from server
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Create file for storing downloaded data
    int filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0700);
    if (filefd == -1) {
        perror("File creation failed");
        exit(EXIT_FAILURE);
    }

    // Download data from server
    while((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        write(filefd, buffer, n);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close sockets and file
    close(filefd);
    close(sockfd);

    return 0;
}