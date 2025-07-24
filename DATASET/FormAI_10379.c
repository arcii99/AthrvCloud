//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MSGSIZE 1024

int main() {
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // server address
    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(sock, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", 8080);

    while (1) {
        socklen_t cli_addr_len = sizeof(cli_addr);
        int cli_sock = accept(sock, (struct sockaddr *)&cli_addr, &cli_addr_len);
        if (cli_sock == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // start reading client messages
        char msg[MSGSIZE];
        ssize_t len = recv(cli_sock, msg, MSGSIZE, 0);

        if (len == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // decrypt message
        // ...

        printf("Received message from %s: %s\n", inet_ntoa(cli_addr.sin_addr), msg);

        // close connection
        close(cli_sock);
    }

    // close socket
    close(sock);

    return 0;
}