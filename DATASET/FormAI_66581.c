//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 143
#define SERVER_NAME "imap.example.com"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];

    // get IP address of server
    host = gethostbyname(SERVER_NAME);
    if (host == NULL) {
        printf("Error: could not resolve host %s\n", SERVER_NAME);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // set server address and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr = *((struct in_addr *) host->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // receive welcome message from server
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send login credentials to server
    sprintf(buffer, "LOGIN username password\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response from server
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // close socket connection
    close(sockfd);

    return 0;
}