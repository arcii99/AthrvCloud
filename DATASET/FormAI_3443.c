//FormAI DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target IP>\n", argv[0]);
        exit(1);
    }

    char *target = argv[1];
    int socket_desc, port, status;
    struct sockaddr_in target_addr;

    for (port=1; port <= 65535; port++) {
        // create socket
        socket_desc = socket(AF_INET , SOCK_STREAM , 0);

        if (socket_desc == -1) {
            printf("Could not create socket");
            continue;
        }

        // setup target address
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(target);
        target_addr.sin_port = htons(port);

        // connect to target
        status = connect(socket_desc, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (status == -1) {
            // port is closed
            printf("Port %d is closed\n", port);
        } else {
            // port is open
            printf("Port %d is open\n", port);
        }

        close(socket_desc);
    }

    return 0;
}