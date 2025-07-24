//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024
#define FTP_PORT 21

// Function to read the server response
void read_response(int sockfd, char *buffer){
    // Read the response from the server
    memset(buffer, 0, MAX_LENGTH);
    read(sockfd, buffer, MAX_LENGTH);
    printf("%s", buffer);
}

int main(int argc, char *argv[]){
    struct sockaddr_in server_addr;
    int sockfd;

    // Check for correct number of arguments
    if (argc < 3) {
        printf("USAGE: ./ftpclient <server_ip> <username> <password>\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        printf("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0){
        printf("Error: Invalid server address.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Error: Connection failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server.\n");

    char buffer[MAX_LENGTH];
    read_response(sockfd, buffer);

    // Send username
    char command[MAX_LENGTH];
    sprintf(command, "USER %s\r\n", argv[2]);
    write(sockfd, command, strlen(command));
    read_response(sockfd, buffer);

    // Send password
    sprintf(command, "PASS %s\r\n", argv[3]);
    write(sockfd, command, strlen(command));
    read_response(sockfd, buffer);

    // Enter passive mode
    sprintf(command, "PASV\r\n");
    write(sockfd, command, strlen(command));
    read_response(sockfd, buffer);

    // Parse server response to get port number
    int port_num = 0;
    char *resp = strtok(buffer, ",");
    for (int i = 0; i < 4; i++){
        resp = strtok(NULL, ",");
    }
    port_num += atoi(resp) * 256;
    resp = strtok(NULL, ",");
    port_num += atoi(resp);

    // Connect to data port
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port_num);
    data_addr.sin_addr = server_addr.sin_addr;

    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sockfd, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0){
        printf("Error: Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send simple command to test data connection
    sprintf(command, "PWD\r\n");
    write(sockfd, command, strlen(command));
    read_response(sockfd, buffer);
    read_response(data_sockfd, buffer);

    // Close data connection
    close(data_sockfd);

    // Quit FTP session
    sprintf(command, "QUIT\r\n");
    write(sockfd, command, strlen(command));
    read_response(sockfd, buffer);

    // Close control connection
    close(sockfd);

    return 0;
}