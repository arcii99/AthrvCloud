//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in target;
    int socket_descriptor, port;
    char *ip_address, response[1024];

    if (argc < 2) {
        printf("Usage: %s <target-ip>\n", argv[0]);
        exit(0);
    }

    ip_address = argv[1];

    printf("Starting port scan on %s\n", ip_address);

    for (port=1; port <= 65535; port++) {
        socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_descriptor < 0) {
            perror("socket() error");
            exit(1);
        }

        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(ip_address);
        target.sin_port = htons(port);

        if (connect(socket_descriptor, (struct sockaddr *)&target, sizeof(target)) == 0) {
            sprintf(response, "Port %d open\n", port);
            printf("%s", response);
            write(socket_descriptor, "PING\r\n", strlen("PING\r\n"));
            read(socket_descriptor, response, sizeof(response));
            printf(" >> %s", response);
        }

        close(socket_descriptor);
    }

    printf("\nPort scan complete.\n");

    return 0;
}