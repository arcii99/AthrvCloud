//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("You forgot to tell me an address to connect to!\n");
        exit(1);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Socket creation failed!\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(8888);

    if (connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed!\n");
        exit(1);
    }

    printf("Connection established! Sending message...\n");
    char msg[] = "Hello, server!";
    write(sock_fd, msg, strlen(msg));

    char recv_buf[1024] = {0};
    read(sock_fd, recv_buf, 1024);
    printf("Received message from server: %s\n", recv_buf);

    close(sock_fd);
    printf("Connection closed. That was exciting!\n");

    return 0;
}