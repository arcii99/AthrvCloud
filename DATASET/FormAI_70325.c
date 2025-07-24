//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define MAX_COMMAND_LENGTH 100

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char command[MAX_COMMAND_LENGTH], buffer[MAX_BUFFER];
    int n;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Error opening socket");

    // Set server address and port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("Invalid address");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting");

    // Receive welcome message
    memset(buffer, 0, MAX_BUFFER);
    if ((n = read(sockfd, buffer, MAX_BUFFER)) < 0)
        error("Error reading from socket");
    printf("%s", buffer);

    // Send user name
    printf("Enter username: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;
    strcat(command, "\r\n");
    if (write(sockfd, command, strlen(command)) < 0)
        error("Error writing to socket");

    // Receive response
    memset(buffer, 0, MAX_BUFFER);
    if ((n = read(sockfd, buffer, MAX_BUFFER)) < 0)
        error("Error reading from socket");
    printf("%s", buffer);

    // Send password
    printf("Enter password: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;
    strcat(command, "\r\n");
    if (write(sockfd, command, strlen(command)) < 0)
        error("Error writing to socket");

    // Receive response
    memset(buffer, 0, MAX_BUFFER);
    if ((n = read(sockfd, buffer, MAX_BUFFER)) < 0)
        error("Error reading from socket");
    printf("%s", buffer);

    // Loop to receive commands and send them to the server
    while (1)
    {
        printf("ftp> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;
        strcat(command, "\r\n");
        if (write(sockfd, command, strlen(command)) < 0)
            error("Error writing to socket");

        // Receive response
        memset(buffer, 0, MAX_BUFFER);
        if ((n = read(sockfd, buffer, MAX_BUFFER)) < 0)
            error("Error reading from socket");
        printf("%s", buffer);

        // Check if we need to close the connection
        if (strncmp(command, "quit", 4) == 0)
            break;
    }

    // Close the socket
    close(sockfd);

    return 0;
}