//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[BUFFER_SIZE], recvline[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address and port number
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    // Connect to server
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Receive welcome message
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send user credentials
    sprintf(sendline, "USER anonymous\r\n");
    write(sockfd, sendline, strlen(sendline));
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send password
    sprintf(sendline, "PASS guest@\r\n");
    write(sockfd, sendline, strlen(sendline));
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Set binary mode
    sprintf(sendline, "TYPE I\r\n");
    write(sockfd, sendline, strlen(sendline));
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Open file for transfer
    FILE *fp;
    fp = fopen("test.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Send STOR command
    sprintf(sendline, "STOR test.txt\r\n");
    write(sockfd, sendline, strlen(sendline));
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send file contents
    int bytesRead = 0;
    while ((bytesRead = fread(sendline, 1, sizeof(sendline), fp)) > 0) {
        write(sockfd, sendline, bytesRead);
    }

    // Close file
    fclose(fp);

    // Quit session
    sprintf(sendline, "QUIT\r\n");
    write(sockfd, sendline, strlen(sendline));
    n = read(sockfd, recvline, sizeof(recvline));
    recvline[n] = '\0';
    printf("%s", recvline);

    // Close socket
    close(sockfd);

    return 0;
}