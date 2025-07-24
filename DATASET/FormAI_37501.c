//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9000
#define IP_ADDRESS "127.0.0.1"

void recursive_echo(int sockfd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t received = recv(sockfd, buffer, sizeof(buffer), 0);

    if (received > 0) {
        printf("Received message: %s\n", buffer);
        send(sockfd, buffer, sizeof(buffer), 0);
        recursive_echo(sockfd);
    } else {
        printf("Connection closed by client\n");
        close(sockfd);
        exit(0);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
  
    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket() error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
  
    // configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() error");
        exit(1);
    }

    // start recursive echo
    recursive_echo(sockfd);

    return 0;
}