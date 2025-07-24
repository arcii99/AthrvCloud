//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scientific
// C program to build an FTP client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

// Function to send and receive data using FTP
void send_recv(int i, int sockfd) {
    char buffer[MAXSIZE];
    char* message = "Hello Server \n";
    memset(buffer, 0, sizeof(buffer));

    // If socket is ready to write, send message to server
    if (i == sockfd) {
        if (send(sockfd, message, strlen(message), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        printf("Hello message sent successfully\n");
    }
    // If socket is ready to read, receive message from server
    else {
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("Server replied: %s\n", buffer);
    }
}

int main() {
    int sockfd, fdmax, i;
    fd_set master;
    fd_set read_fds;

    struct sockaddr_in server_addr;

    FD_ZERO(&master);
    FD_ZERO(&read_fds);

    // Creating socket for FTP
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Setting properties for FTP client
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    // Connecting FTP client to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    FD_SET(sockfd, &master);
    FD_SET(STDIN_FILENO, &master);
    fdmax = sockfd;

    // Starting infinite loop for FTP client
    while (1) {
        read_fds = master;
        if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Reading user input
        for (i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &read_fds)) {
                send_recv(i, sockfd);
            }
        }
    }

    close(sockfd);
    return 0;
}