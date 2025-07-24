//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_PORT 110

int main(int argc, char *argv[]){
    int sockfd;
    char buffer[1024];
    char user[50];
    char pass[50];
    char command[100];
    struct sockaddr_in serv_addr;
    int n;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("ERROR invalid server address");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive server greeting
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s",buffer);

    // send username
    printf("Username: ");
    fgets(user,50,stdin);
    sprintf(command, "USER %s", user);
    write(sockfd, command, strlen(command));
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s",buffer);

    // send password
    printf("Password: ");
    fgets(pass,50,stdin);
    sprintf(command, "PASS %s", pass);
    write(sockfd, command, strlen(command));
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s",buffer);

    // retrieve list of messages
    sprintf(command, "LIST");
    write(sockfd, command, strlen(command));
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s",buffer);

    // quit connection
    sprintf(command, "QUIT");
    write(sockfd, command, strlen(command));
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s",buffer);

    close(sockfd);

    return 0;
}