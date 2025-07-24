//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
// FTP client program in distributed style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define MAXSIZE 1024
#define COMMANDSIZE 100

int main(int argc, char* argv[]) {
    struct sockaddr_in serverAddress;
    int sockfd;
    char buffer[MAXSIZE], user[COMMANDSIZE], pass[COMMANDSIZE], cmd[COMMANDSIZE];

    if(argc < 2) {
        printf("Usage: %s <Server Address>\n", argv[0]);
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(0);
    }

    // Set the server address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serverAddress.sin_addr);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error connecting to server");
        exit(0);
    }

    // Receive the welcome message
    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving message from server");
        exit(0);
    }
    printf("Welcome message from server: %s\n", buffer);

    // Login to the FTP server
    printf("Username: ");
    fgets(user, COMMANDSIZE, stdin);
    user[strcspn(user, "\n")] = 0;
    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving message from server");
        exit(0);
    }

    printf("%s\n", buffer);

    printf("Password: ");
    fgets(pass, COMMANDSIZE, stdin);
    pass[strcspn(pass, "\n")] = 0;
    sprintf(buffer, "PASS %s\r\n", pass);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving message from server");
        exit(0);
    }

    printf("%s\n", buffer);

    // Enter the command loop
    while(1) {
        printf("ftp> ");
        fgets(cmd, COMMANDSIZE, stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        // Send the command to the server
        strcat(cmd, "\r\n");
        send(sockfd, cmd, strlen(cmd), 0);

        // Receive the response from the server
        memset(buffer, 0, sizeof(buffer));
        if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Error receiving message from server");
            exit(0);
        }

        printf("%s\n", buffer);

        // Quit command exits the loop
        if(strncmp(cmd, "QUIT", 4) == 0) {
            break;
        }
    }

    // Close the socket and exit
    close(sockfd);
    return 0;
}