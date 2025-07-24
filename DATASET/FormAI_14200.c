//FormAI DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in target;
    char *target_ip;
    int start_port, end_port;

    if(argc != 4)
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);

    target_ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Creating a socket to connect to the target
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Setup target information
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_ip);

    // Scan all the ports in the specified range
    for(int port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Try connecting to the target on the given port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            // Port is closed
        }
        close(sock);
    }

    return 0;
}