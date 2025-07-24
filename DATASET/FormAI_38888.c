//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [ip address] [port number] [email address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get input arguments
    char *ip_addr_str = argv[1];
    int port_num = atoi(argv[2]);
    char *email_addr = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket to non-blocking mode
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl get failed");
        exit(EXIT_FAILURE);
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl set failed");
        exit(EXIT_FAILURE);
    }

    // Set up address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);

    int ret = inet_pton(AF_INET, ip_addr_str, &serv_addr.sin_addr);
    if (ret == 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(EXIT_FAILURE);
    } else if (ret == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    fd_set write_fds, read_fds;
    FD_ZERO(&write_fds);
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    FD_SET(sockfd, &write_fds);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1 && errno != EINPROGRESS) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    int select_ret = select(sockfd + 1, &read_fds, &write_fds, NULL, &timeout);

    if (select_ret == -1) {
        perror("select failed");
        exit(EXIT_FAILURE);
    } else if (select_ret == 0) {
        fprintf(stderr, "Timeout\n");
        exit(EXIT_FAILURE);
    } else {
        if (FD_ISSET(sockfd, &write_fds) || FD_ISSET(sockfd, &read_fds)) {
            socklen_t len = sizeof(int);
            int error = 0;
            ret = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
            if (ret == -1) {
                perror("getsockopt failed");
                exit(EXIT_FAILURE);
            } else if (error != 0) {
                fprintf(stderr, "Error in connection\n");
            } else {
                printf("Connection established\n");
            }
        }
    }

    // Send HELO command to server
    char buf[BUF_SIZE];
    sprintf(buf, "HELO %s\r\n", email_addr);

    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    } else {
        printf("HELO sent\n");
    }

    // Receive response from server
    memset(buf, 0, BUF_SIZE);
    ret = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if (ret == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Response: %s", buf);
    }

    // Send QUIT command to server
    sprintf(buf, "QUIT\r\n");

    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    } else {
        printf("QUIT sent\n");
    }

    // Receive response from server
    memset(buf, 0, BUF_SIZE);
    ret = recv(sockfd, buf, BUF_SIZE - 1, 0);
    if (ret == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Response: %s", buf);
    }

    // Close socket
    close(sockfd);

    return 0;
}