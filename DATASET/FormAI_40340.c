//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    // define socket variables
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buff[1024], filename[20];
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // set servaddr values
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // receive initial response from server
    n = read(sockfd, buff, sizeof(buff));
    buff[n] = '\0'; // add null terminator
    printf("%s", buff);

    // send username to server
    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);
    write(sockfd, username, strlen(username));
    n = read(sockfd, buff, sizeof(buff));
    buff[n] = '\0';
    printf("%s", buff);

    // send password to server
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);
    write(sockfd, password, strlen(password));
    n = read(sockfd, buff, sizeof(buff));
    buff[n] = '\0';
    printf("%s", buff);

    // enter passive mode
    write(sockfd, "PASV\r\n", strlen("PASV\r\n"));
    n = read(sockfd, buff, sizeof(buff));
    buff[n] = '\0';
    printf("%s", buff);

    // get IP address and port for data connection
    int ip1, ip2, ip3, ip4, port1, port2;
    sscanf(buff, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n",
           &ip1, &ip2, &ip3, &ip4, &port1, &port2);
    char dataip[20];
    sprintf(dataip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
    int dataport = (port1 * 256) + port2;

    // ask user for file to retrieve
    printf("Enter filename to retrieve: ");
    scanf("%s", filename);

    // open data socket and retrieve file from server
    int datasockfd;
    struct sockaddr_in dataservaddr;
    char databuff[1024];
    FILE *fp;
    
    datasockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (datasockfd == -1) {
        perror("Error creating data socket");
        exit(1);
    }

    memset(&dataservaddr, 0, sizeof(dataservaddr));
    dataservaddr.sin_family = AF_INET;
    dataservaddr.sin_port = htons(dataport);
    dataservaddr.sin_addr.s_addr = inet_addr(dataip);

    if (connect(datasockfd, (struct sockaddr *)&dataservaddr, sizeof(dataservaddr)) != 0) {
        perror("Error connecting to data server");
        exit(1);
    }

    write(sockfd, "RETR ", strlen("RETR "));
    write(sockfd, filename, strlen(filename));
    write(sockfd, "\r\n", strlen("\r\n"));

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error creating file");
        exit(1);
    }

    while ((n = read(datasockfd, databuff, sizeof(databuff))) > 0 ) {
        fwrite(databuff, sizeof(char), n, fp);
    }

    // print confirmation message
    printf("File '%s' retrieved successfully.\n", filename);

    // close sockets and file
    close(sockfd);
    close(datasockfd);
    fclose(fp);

    return 0;
}