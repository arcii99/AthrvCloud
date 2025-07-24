//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

/* Function to setup a connection to a URL */
int open_connection(char *HOST, int PORT) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_info;
    server_info.sin_family = AF_INET;
    server_info.sin_addr.s_addr = inet_addr(HOST);
    server_info.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_info, sizeof(server_info)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    return sock;
}

/* Main function */
int main(int argc, char** argv) {
    char *request_header = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: HTTP-CLIENT\r\nConnection: close\r\n\r\n";
    char *host = "www.example.com";
    int port = 80;
    int sockfd, n;
    char buffer[MAX_BUFFER_SIZE];

    sockfd = open_connection(host, port);

    /* Send HTTP GET request to server */
    sprintf(buffer, request_header, host);
    send(sockfd, buffer, strlen(buffer), 0);

    /* Receive and print HTTP response */
    while ((n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    /* Close the connection */
    close(sockfd);

    return 0;
}