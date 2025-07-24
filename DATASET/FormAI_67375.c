//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>

void scan_port(char *ip, int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);
    int status = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if (status == 0) {
        printf("[%d] open\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("[%d] closed\n", port);
        } else {
            printf("[%d] error\n", port);
        }
    }
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(EXIT_FAILURE);
    }
    if (start_port > end_port) {
        fprintf(stderr, "Start port must be lower than end port\n");
        exit(EXIT_FAILURE);
    }
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }
    return 0;
}