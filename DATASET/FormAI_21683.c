//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXLINE 4096
#define PORT_NUM 110 // Port number for POP3 server
#define HOST_NAME "pop3.server.com" // Hostname of POP3 server

int main()
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        return -1;
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT_NUM);

    if ((inet_pton(AF_INET, HOST_NAME, &servaddr.sin_addr)) <= 0)
    {
        perror("inet_pton error");
        return -1;
    }

    // Connect to server
    if ((connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
    {
        perror("connect error");
        return -1;
    }

    // Read greeting from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {
        perror("read error");
        return -1;
    }

    recvline[n] = '\0';  // Null terminate string

    // Print greeting
    printf("%s", recvline);

    // Send user ID
    char user[MAXLINE + 1];
    printf("User: ");
    fgets(user, MAXLINE, stdin);  // Get user input
    sprintf(recvline, "USER %s", user);
    write(sockfd, recvline, strlen(recvline));  // Send to server

    // Read response from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {
        perror("read error");
        return -1;
    }

    recvline[n] = '\0';  // Null terminate string

    // Print response
    printf("%s", recvline);

    // Send password
    char pass[MAXLINE + 1];
    printf("Password: ");
    fgets(pass, MAXLINE, stdin);  // Get user input
    sprintf(recvline, "PASS %s", pass);
    write(sockfd, recvline, strlen(recvline));  // Send to server

    // Read response from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {
        perror("read error");
        return -1;
    }

    recvline[n] = '\0';  // Null terminate string

    // Print response
    printf("%s", recvline);

    // Send command to retrieve mailbox stats
    sprintf(recvline, "STAT");
    write(sockfd, recvline, strlen(recvline));  // Send to server

    // Read response from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {
        perror("read error");
        return -1;
    }

    recvline[n] = '\0';  // Null terminate string

    // Print response
    printf("%s", recvline);

    // Send quit command
    sprintf(recvline, "QUIT");
    write(sockfd, recvline, strlen(recvline));  // Send to server

    // Read response from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {
        perror("read error");
        return -1;
    }

    recvline[n] = '\0';  // Null terminate string

    // Print response
    printf("%s", recvline);

    // Close socket
    close(sockfd);

    return 0;
}