//FormAI DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PORT 8000

int main() {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // define address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // bind
    if (bind(sockfd, (struct sockaddr*) &addr, sizeof(addr))) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen
    if (listen(sockfd, 3)) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // accept
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &len);
    if (client_sockfd == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // read message from client
    char buffer[1024] = {0};
    read(client_sockfd, buffer, 1024);

    // validate message
    const char *secret = "mysupersecretcode";
    if (strcmp(buffer, secret) != 0) {  // message is invalid, close connection
        close(client_sockfd);
        close(sockfd);
        exit(EXIT_SUCCESS);
    }

    // send message to client
    char *message = "Hello, client!\n";
    write(client_sockfd, message, strlen(message));

    // close connection
    close(client_sockfd);
    close(sockfd);

    return 0;
}