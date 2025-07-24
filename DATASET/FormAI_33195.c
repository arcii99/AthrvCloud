//FormAI DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    char *ip = "127.0.0.1";
    int start_port = 1;
    int end_port = 65535;

    if(sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    printf("Starting scan on %s from port %d to %d\n", ip, start_port, end_port);

    int i;
    for(i = start_port; i <= end_port; i++) {
        server.sin_port = htons(i);
        if(connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    printf("Scan complete\n");
    return 0;
}