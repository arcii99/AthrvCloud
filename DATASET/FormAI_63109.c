//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORTNO 21

int main(int argc, char *argv[]) {
    int sockfd, n;
    char sendbuf[BUFSIZE], recvbuf[BUFSIZE];
    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORTNO);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Error invalid server address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read welcome message from server
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);

    // Send username and password
    sprintf(sendbuf, "USER %s\r\n", argv[2]);
    write(sockfd, sendbuf, strlen(sendbuf));
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);
    sprintf(sendbuf, "PASS %s\r\n", argv[3]);
    write(sockfd, sendbuf, strlen(sendbuf));
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);

    // Change to binary mode
    sprintf(sendbuf, "TYPE I\r\n");
    write(sockfd, sendbuf, strlen(sendbuf));
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);

    // Retrieve file from server
    sprintf(sendbuf, "RETR %s\r\n", argv[4]);
    write(sockfd, sendbuf, strlen(sendbuf));
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);

    // Read file contents and save to local file
    FILE *fp = fopen(argv[5], "wb");
    while ((n = read(sockfd, recvbuf, BUFSIZE-1)) > 0) {
        fwrite(recvbuf, sizeof(char), n, fp);
    }
    fclose(fp);

    // Logout and disconnect from server
    sprintf(sendbuf, "QUIT\r\n");
    write(sockfd, sendbuf, strlen(sendbuf));
    n = read(sockfd, recvbuf, BUFSIZE-1);
    recvbuf[n] = '\0';
    printf("%s", recvbuf);
    close(sockfd);

    return 0;
}