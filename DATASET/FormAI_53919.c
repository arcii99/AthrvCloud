//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 21 // FTP port number

int main(int argc, char **argv) {
    int sockfd, n, bufsize = 1024;
    char recvline[bufsize], sendline[bufsize];
    struct sockaddr_in servaddr;

    // check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address of FTP server> <FTP username>\n", argv[0]);
        exit(1);
    }

    // create socket for communication
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // set server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error: Could not connect to server");
        exit(1);
    }

    // receive welcome message from server
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // send username to server
    sprintf(sendline, "USER %s\r\n", argv[2]);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("Error: Could not write to server");
        exit(1);
    }

    // receive response from server
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // enter password
    printf("Password: ");
    fgets(sendline, bufsize, stdin);
    sprintf(sendline, "PASS %s\r\n", sendline);

    // send password to server
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("Error: Could not write to server");
        exit(1);
    }

    // receive response from server
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // enter passive mode
    if (write(sockfd, "PASV\r\n", strlen("PASV\r\n")) < 0) {
        perror("Error: Could not write to server");
        exit(1);
    }
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // parse response to get IP and port number to connect to
    char *p1, *p2;
    int ip1, ip2, ip3, ip4, port1, port2;
    p1 = strchr(recvline, '(');
    p2 = strchr(recvline, ')');
    sscanf(p1+1, "%d,%d,%d,%d,%d,%d", &ip1, &ip2, &ip3, &ip4, &port1, &port2);
    char ip_addr[32];
    sprintf(ip_addr, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // set data server address and port
    struct sockaddr_in data_servaddr;
    memset(&data_servaddr, 0, sizeof(data_servaddr));
    data_servaddr.sin_family = AF_INET;
    data_servaddr.sin_port = htons(port1*256+port2);
    inet_pton(AF_INET, ip_addr, &data_servaddr.sin_addr);

    // connect to data server
    if (connect(data_sockfd, (struct sockaddr *) &data_servaddr, sizeof(data_servaddr)) < 0) {
        perror("Error: Could not connect to data server");
        exit(1);
    }

    // send RETR command to server
    printf("Enter name of file to download: ");
    fgets(sendline, bufsize, stdin);
    sprintf(sendline, "RETR %s\r\n", sendline);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("Error: Could not write to server");
        exit(1);
    }

    // receive response from server
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // receive file from server
    FILE *file = fopen(sendline, "w");
    while ((n = read(data_sockfd, recvline, bufsize-1)) > 0) {
        recvline[n] = '\0';
        fprintf(file, "%s", recvline);
        printf("%s", recvline);
    }
    if (n < 0) {
        perror("Error: Could not read from data server");
        exit(1);
    }
    fclose(file);

    // send QUIT command to server
    if (write(sockfd, "QUIT\r\n", strlen("QUIT\r\n")) < 0) {
        perror("Error: Could not write to server");
        exit(1);
    }

    // receive response from server
    n = read(sockfd, recvline, bufsize-1);
    if (n < 0) {
        perror("Error: Could not read from server");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // close socket
    close(sockfd);

    return 0;
}