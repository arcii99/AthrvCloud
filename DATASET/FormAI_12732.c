//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 21 // Default FTP port number
#define USER "USERNAME" // FTP Server username
#define PASSWORD "PASSWORD" // FTP Server password

int sockfd;
char recvline[MAXLINE + 1];
struct sockaddr_in servaddr;

/**
 * Connect and Read FTP Server Response
 **/
void ftpConnect(char *ipaddress) {
    char *username, *password;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    // Convert IP address to binary representation
    if (inet_pton(AF_INET, ipaddress, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error: %s\n", strerror(errno));
    }

    // Connect to FTP Server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
    }

    // Read Response
    readResponse();
}

/**
 * Read FTP Server Response
 **/
void readResponse() {
    bzero(recvline, MAXLINE);
    if (read(sockfd, recvline, MAXLINE) < 0) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
    }
    printf("%s", recvline);
}

/**
 * Send FTP Command
 **/
void sendCommand(char *cmd) {
    if (write(sockfd, cmd, strlen(cmd)) < 0) {
        fprintf(stderr, "write error: %s\n", strerror(errno));
    }

    // Read Response
    readResponse();
}

/**
 * Login to FTP Server
 **/
void login() {
    char *username, *password;
    username = USER;
    password = PASSWORD;

    // Send Username
    sendCommand("USER ");
    sendCommand(username);

    // Send Password
    sendCommand("PASS ");
    sendCommand(password);
}

/**
 * Quit FTP Server
 **/
void quit() {
    sendCommand("QUIT");
    close(sockfd);
}

/**
 * Main Function
 **/
int main(int argc, char **argv) {
    char *ipaddress, *filename;

    if(argc < 2) {
        fprintf(stderr, "Usage: ./ftpclient IPADDRESS FILENAME\n");
        exit(1);
    }

    ipaddress = argv[1];
    filename = argv[2];

    ftpConnect(ipaddress);
    login();

    sendCommand("TYPE I"); // Set transfer mode to binary
    sendCommand("PASV"); // Set operation to passive

    // Retrieve file
    char cmd[MAXLINE];
    sprintf(cmd, "RETR %s\n", filename);
    sendCommand(cmd);

    // Receive file
    int n;
    char recvbuf[MAXLINE];
    FILE *fp;

    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "fopen error: %s\n", strerror(errno));
    }

    while ((n = read(sockfd, recvbuf, MAXLINE)) > 0) {
        fwrite(recvbuf, sizeof(char), n, fp);
    }

    fclose(fp);
    quit();

    return 0;
}