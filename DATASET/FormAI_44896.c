//FormAI DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *target = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning %s for open ports between %d-%d\n", target, start_port, end_port);

    // Create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(target);
    server.sin_family = AF_INET;

    // Scan range of ports
    for (int i = start_port; i <= end_port; i++) {
        server.sin_port = htons(i);

        // Connect to port
        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
            printf("Port %d closed\n", i);
        } else {
            printf("Port %d open\n", i);
        }

        close(socket_desc);
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    }

    close(socket_desc);

    return 0;
}