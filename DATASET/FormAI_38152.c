//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 64
#define MAX_RESPONSE_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: ./pop3_client [username] [password] [server_address]\n");
        return 1;
    }
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    
    portno = 110;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[3], &serv_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    bzero(response, MAX_RESPONSE_LENGTH);
    n = read(sockfd, response, MAX_RESPONSE_LENGTH - 1);

    sprintf(command, "USER %s\r\n", argv[1]);
    write(sockfd, command, strlen(command));

    bzero(response, MAX_RESPONSE_LENGTH);
    n = read(sockfd, response, MAX_RESPONSE_LENGTH - 1);

    sprintf(command, "PASS %s\r\n", argv[2]);
    write(sockfd, command, strlen(command));

    bzero(response, MAX_RESPONSE_LENGTH);
    n = read(sockfd, response, MAX_RESPONSE_LENGTH - 1);

    sprintf(command, "STAT\r\n");
    write(sockfd, command, strlen(command));

    bzero(response, MAX_RESPONSE_LENGTH);
    n = read(sockfd, response, MAX_RESPONSE_LENGTH - 1);

    printf("Server response:\n%s\n", response);

    close(sockfd);

    return 0;
}