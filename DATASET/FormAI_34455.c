//FormAI DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    char *ip_address = argv[1];
    int start_port, end_port;
    if (argc == 4) {
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    } else {
        printf("Usage: ./portscanner ip_address start_port end_port\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int connected;
    int i;
    for (i = start_port; i <= end_port; i++) {
        server_address.sin_port = htons(i);
        connected = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
        if (connected == 0) {
            printf("Port %d is open\n", ntohs(server_address.sin_port));
        }
    }

    printf("Port scan complete\n");
    close(sock);
    return 0;
}