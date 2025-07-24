//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    int sockfd, rval;
    char buf[MAX_LINE_LENGTH];
    struct sockaddr_in servaddr;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server IP> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(143);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive the initial greeting from the server
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Send the login command to the server
    snprintf(buf, MAX_LINE_LENGTH, "A001 LOGIN %s %s\r\n", argv[2], argv[3]);
    rval = write(sockfd, buf, strlen(buf));
    if (rval < 0) {
        perror("write");
        exit(1);
    }

    // Wait for the server's response to the login command
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Send the select command to the server
    snprintf(buf, MAX_LINE_LENGTH, "A002 SELECT inbox\r\n");
    rval = write(sockfd, buf, strlen(buf));
    if (rval < 0) {
        perror("write");
        exit(1);
    }

    // Wait for the server's response to the select command
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Send the fetch command to the server to retrieve the first message
    snprintf(buf, MAX_LINE_LENGTH, "A003 FETCH 1 BODY[HEADER]\r\n");
    rval = write(sockfd, buf, strlen(buf));
    if (rval < 0) {
        perror("write");
        exit(1);
    }

    // Wait for the server's response containing the message header
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Send the fetch command to the server to retrieve the first message's body
    snprintf(buf, MAX_LINE_LENGTH, "A004 FETCH 1 BODY[TEXT]\r\n");
    rval = write(sockfd, buf, strlen(buf));
    if (rval < 0) {
        perror("write");
        exit(1);
    }

    // Wait for the server's response containing the message body
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Send the logout command to the server
    snprintf(buf, MAX_LINE_LENGTH, "A005 LOGOUT\r\n");
    rval = write(sockfd, buf, strlen(buf));
    if (rval < 0) {
        perror("write");
        exit(1);
    }

    // Wait for the server's response to the logout command
    rval = read(sockfd, buf, MAX_LINE_LENGTH - 1);
    if (rval < 0) {
        perror("read");
        exit(1);
    }
    buf[rval] = '\0';
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}