//FormAI DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int socket_descriptor = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip);
    server_address.sin_port = htons(port);

    int connection_status = connect(socket_descriptor, (struct sockaddr*)&server_address, sizeof(server_address));
    if (connection_status == -1) {
        fprintf(stderr, "Failed to connect to %s:%d: %s\n", ip, port, strerror(errno));
        close(socket_descriptor);
        exit(EXIT_FAILURE);
    }

    printf("Port %d is open on %s\n", port, ip);

    close(socket_descriptor);

    return 0;
}