//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21 // FTP control port
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    
    // Checking command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }
    
    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    // Setting up server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }
    
    // Connecting to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receiving welcome message
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s", buffer);
    
    // Sending username to server
    char user[MAXLINE];
    sprintf(user, "USER %s\r\n", argv[2]);
    n = write(sockfd, user, strlen(user));
    if (n < 0) {
        perror("write");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s", buffer);
    
    // Waiting for password
    printf("Enter password: ");
    char pass[MAXLINE];
    scanf("%s", pass);
    
    // Sending password to server
    char password[MAXLINE];
    sprintf(password, "PASS %s\r\n", pass);
    n = write(sockfd, password, strlen(password));
    if (n < 0) {
        perror("write");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s", buffer);
    
    // Entering passive mode
    n = write(sockfd, "PASV\r\n", 6);
    if (n < 0) {
        perror("write");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    char *p1 = strrchr(buffer, '(') + 1;
    char *p2 = strchr(buffer, ')');
    *p2 = '\0';
    int nums[6];
    sscanf(p1, "%d,%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]);
    char ipaddr[MAXLINE];
    sprintf(ipaddr, "%d.%d.%d.%d", nums[0], nums[1], nums[2], nums[3]);
    int dataport = nums[4] * 256 + nums[5];
    printf("FTP server data port: %d\n", dataport);
    
    // Connecting to FTP data port
    int datafd;
    struct sockaddr_in datapaddr;
    datafd = socket(AF_INET, SOCK_STREAM, 0);
    if (datafd < 0) {
        perror("socket");
        exit(1);
    }
    bzero(&datapaddr, sizeof(datapaddr));
    datapaddr.sin_family = AF_INET;
    datapaddr.sin_port = htons(dataport);
    if (inet_pton(AF_INET, ipaddr, &datapaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", ipaddr);
        exit(1);
    }
    if (connect(datafd, (struct sockaddr *) &datapaddr, sizeof(datapaddr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    // Sending retr command to server
    char retr[MAXLINE];
    printf("Enter filename to download: ");
    char fname[MAXLINE];
    scanf("%s", fname);
    sprintf(retr, "RETR %s\r\n", fname);
    n = write(sockfd, retr, strlen(retr));
    if (n < 0) {
        perror("write");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s", buffer);
    
    // Receiving file content
    bzero(buffer, sizeof(buffer));
    FILE *fp = fopen(fname, "wb");
    while ((n = read(datafd, buffer, MAXLINE)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }
    if (n < 0) {
        perror("read");
        exit(1);
    }
    fclose(fp);
    printf("Downloaded file: %s\n", fname);
    
    // Closing FTP data port connection
    close(datafd);
    
    // Sending quit command to server
    n = write(sockfd, "QUIT\r\n", 6);
    if (n < 0) {
        perror("write");
        exit(1);
    }
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Response from server: %s", buffer);
    
    // Closing FTP control port connection
    close(sockfd);
    
    return 0;
}