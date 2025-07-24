//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024
#define FTP_PORT 21

// function to read response from the server
void readResponse(int sockfd, char *buffer) {
    int n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("Error in reading response");
        exit(1);
    }
    buffer[n] = '\0';
}

// function to send command to the server
void sendCommand(int sockfd, char *buffer) {
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error in sending command");
        exit(1);
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE], username[MAXLINE], password[MAXLINE];

    if (argc != 2) {
        printf("Usage: %s <FTP server IP>\n", argv[0]);
        exit(1);
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Error");
        exit(1);
    }

    // set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connect Error");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], FTP_PORT);

    // read welcome message from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // get username from user
    printf("Username: ");
    fgets(username, MAXLINE, stdin);
    username[strcspn(username, "\n")] = 0;

    // send username to server
    sprintf(buffer, "USER %s\r\n", username);
    sendCommand(sockfd, buffer);

    // read response from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // get password from user
    printf("Password: ");
    fgets(password, MAXLINE, stdin);
    password[strcspn(password, "\n")] = 0;

    // send password to server
    sprintf(buffer, "PASS %s\r\n", password);
    sendCommand(sockfd, buffer);

    // read response from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // send PASV command to server
    sendCommand(sockfd, "PASV\r\n");

    // read response from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // parse IP and port from response
    char *token;
    char *ip_address;
    int port;
    char ip1[4], ip2[4], ip3[4], ip4[4];
    sscanf(buffer, "227 Entering Passive Mode (%[^,],%d,%d,%d,%d,%d,%d)",
           ip1, ip2, ip3, ip4, &port, &port, &port);
    ip_address = strcat(strcat(strcat(strcat(ip1, "."), ip2), "."), strcat(strcat(ip3, "."), ip4));

    // create socket for data transfer
    int data_socket;
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Data Socket Creation Error");
        exit(1);
    }

    // set data socket address
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &data_addr.sin_addr) <= 0) {
        perror("Data Socket inet_pton error");
        exit(1);
    }

    // connect to data socket
    if (connect(data_socket, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
        perror("Data Socket Connect Error");
        exit(1);
    }

    // send LIST command to server
    sendCommand(sockfd, "LIST\r\n");

    // read response from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // read data from data socket
    while (1) {
        int n = read(data_socket, buffer, MAXLINE);
        if (n == 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // close data socket
    close(data_socket);

    // send QUIT command to server
    sendCommand(sockfd, "QUIT\r\n");

    // read response from server
    readResponse(sockfd, buffer);
    printf("%s", buffer);

    // close control socket
    close(sockfd);

    return 0;
}