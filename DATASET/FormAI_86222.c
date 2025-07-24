//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send a command to the server and read its response
void sendCommand(int sockfd, const char* command, char* response) {
    char buffer[BUFFER_SIZE] = {0};
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    strcpy(response, buffer);
}

int main() {
    int sockfd = 0, n = 0;
    char recvBuff[BUFFER_SIZE], user[64], pass[64], command[1024];
    struct sockaddr_in serv_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    // Set the server address and port
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110); // POP3 port
    // Set the server IP address (replace with your own)
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n inet_pton error occured\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Error : Connect Failed \n");
        return 1;
    }

    // Read the server greeting message
    memset(recvBuff, '0', sizeof(recvBuff));
    n = recv(sockfd, recvBuff, sizeof(recvBuff)-1, 0);
    if (n < 0) {
        printf("\n Read error \n");
        return 1;
    }
    printf("%s\n", recvBuff);

    // Send the USER command
    printf("Enter username:\n");
    fgets(user, sizeof(user), stdin);
    snprintf(command, sizeof(command), "USER %s", user);
    sendCommand(sockfd, command, recvBuff);
    printf("%s\n", recvBuff);

    // Send the PASS command
    printf("Enter password:\n");
    fgets(pass, sizeof(pass), stdin);
    snprintf(command, sizeof(command), "PASS %s", pass);
    sendCommand(sockfd, command, recvBuff);
    printf("%s\n", recvBuff);

    // Send the STAT command to get the number of messages
    sendCommand(sockfd, "STAT", recvBuff);
    printf("%s\n", recvBuff);

    // Send the LIST command to get the message list
    sendCommand(sockfd, "LIST", recvBuff);
    printf("%s\n", recvBuff);

    // Send the RETR command to read a message
    printf("Enter message number:\n");
    fgets(command, sizeof(command), stdin);
    snprintf(command, sizeof(command), "RETR %s", command);
    sendCommand(sockfd, command, recvBuff);
    printf("%s\n", recvBuff);

    // Send the QUIT command
    sendCommand(sockfd, "QUIT", recvBuff);
    printf("%s\n", recvBuff);

    // Close the socket
    close(sockfd);

    return 0;
}