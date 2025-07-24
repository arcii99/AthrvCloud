//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>

#define PORT 5000
#define MAX_BUFFER_SIZE 8192

int main()
{
    int sockfd, n;
    char send_buffer[MAX_BUFFER_SIZE];
    char recv_buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Clearing server address structure
    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server address structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("Connect error");
        exit(EXIT_FAILURE);
    }

    // Sending data to server
    bzero(send_buffer, MAX_BUFFER_SIZE);
    strcpy(send_buffer, "Hello from client");
    write(sockfd, send_buffer, strlen(send_buffer));

    // Receiving data from server
    bzero(recv_buffer, MAX_BUFFER_SIZE);
    read(sockfd, recv_buffer, sizeof(recv_buffer)-1);
    printf("Received from server: %s\n", recv_buffer);

    close(sockfd);

    return 0;
}