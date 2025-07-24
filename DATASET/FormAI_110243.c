//FormAI DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    printf("Thank you for choosing our Socket programming example!\n");

    // create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        printf("Oh no! Something went wrong creating the socket.\n");
        exit(1);
    }

    printf("We successfully created the socket. Hooray!\n");

    // set up server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    // bind socket to server address
    int bind_res = bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (bind_res < 0) {
        printf("Uh oh, something went wrong binding the socket to the server address.\n");
        exit(1);
    }

    printf("We successfully bound the socket to the server address. Hooray!\n");

    // start listening for connections
    int listen_res = listen(sock_fd, 10);
    if (listen_res < 0) {
        printf("Oh no, we failed to start listening for connections.\n");
        exit(1);
    }

    printf("We're listening for connections! Hooray!\n");

    // accept incoming connections
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char buffer[256];

    int conn_fd = accept(sock_fd, (struct sockaddr*)&cli_addr, &cli_len);
    if (conn_fd < 0) {
        printf("Oh no! We failed to accept the incoming connection.\n");
        exit(1);
    }

    printf("We accepted the connection. Hooray!\n");

    // read data from the socket
    int read_res = read(conn_fd, buffer, 255);
    if (read_res < 0) {
        printf("Uh oh, there was an error reading from the socket.\n");
        exit(1);
    }

    printf("We successfully read from the socket. Hooray!\n");
    printf("Here's the message received: %s\n", buffer);

    // close the connection and socket
    close(conn_fd);
    close(sock_fd);

    printf("Thank you for trying out our Socket programming example! We hope you had a great experience.\n");

    return 0;
}