//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h> 

#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc , char *argv[]) {
    int socket_fd, port_number, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    port_number = atoi(argv[2]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    if (connect(socket_fd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        error("Error connecting");
    }

    char *http_request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    n = write(socket_fd, http_request, strlen(http_request));
    if (n < 0) {
        error("Error writing to socket");
    }

    bzero(buffer,MAX_BUFFER_SIZE);
    n = read(socket_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("%s\n",buffer);

    close(socket_fd);
    return 0;
}