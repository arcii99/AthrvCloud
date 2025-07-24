//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>

#define SERVER_PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, n;
    char recvline[BUFSIZE + 1];
    char username[BUFSIZE + 1], password[BUFSIZE + 1], ftp_response[BUFSIZE + 1];
    char command[BUFSIZE + 1], argument[BUFSIZE + 1];
    char* host = argv[1];
    struct sockaddr_in serveraddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Fill server address
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, host, &serveraddr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive welcome message from server
    bzero(recvline, BUFSIZE + 1);
    if (read(sockfd, recvline, BUFSIZE) < 0) {
        perror("Error receiving welcome message");
        exit(1);
    }
    printf("%s", recvline);

    // Prompt for user credentials
    printf("Username: ");
    fgets(username, BUFSIZE, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password: ");
    fgets(password, BUFSIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    // Send username
    sprintf(command, "USER %s\r\n", username);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error sending username");
        exit(1);
    }

    // Receive response from server
    bzero(ftp_response, BUFSIZE + 1);
    if (read(sockfd, ftp_response, BUFSIZE) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s", ftp_response);

    // Send password
    sprintf(command, "PASS %s\r\n", password);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("Error sending password");
        exit(1);
    }

    // Receive response from server
    bzero(ftp_response, BUFSIZE + 1);
    if (read(sockfd, ftp_response, BUFSIZE) < 0) {
        perror("Error receiving response");
        exit(1);
    }
    printf("%s", ftp_response);

    // Enter a loop to receive commands and send them to the server
    while(1) {

        printf("> ");
        fgets(command, BUFSIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        // Split command and argument
        char* cmd = strtok(command, " ");
        char* arg = strtok(NULL, "");

        // Send command
        sprintf(command, "%s %s\r\n", cmd, arg);
        if (write(sockfd, command, strlen(command)) < 0) {
            perror("Error sending command");
            exit(1);
        }

        // Receive response from server
        bzero(ftp_response, BUFSIZE + 1);
        if (read(sockfd, ftp_response, BUFSIZE) < 0) {
            perror("Error receiving response");
            exit(1);
        }
        printf("%s", ftp_response);

    }

    // Close socket
    close(sockfd);

    return 0;
}