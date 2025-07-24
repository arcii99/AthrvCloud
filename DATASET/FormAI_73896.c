//FormAI DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <string.h> // for string manipulation functions
#include <stdlib.h> // for dynamic memory allocation functions
#include <unistd.h> // for close() function
#include <sys/socket.h> // for socket functions
#include <arpa/inet.h> // for inet_pton() function

#define SERVER_PORT 8080

int main(int argc, char const *argv[]) {
    // create socket file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // create sockaddr_in structure and fill in server details
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // convert the server IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) == -1) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    // send message to the server
    char msg[] = "Hello Server!";
    size_t msg_len = strlen(msg);
    if (send(sock_fd, msg, msg_len, 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive message from the server
    char buffer[1024] = {0};
    int recv_len;
    if ((recv_len = recv(sock_fd, buffer, 1024, 0)) == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    // print the received message
    printf("Server replied: %s\n", buffer);

    // close the socket file descriptor
    close(sock_fd);

    return 0;
}