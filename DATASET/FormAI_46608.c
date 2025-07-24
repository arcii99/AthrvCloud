//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MIN_PORT 1
#define MAX_PORT 65535

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }
    
    char *target_ip = argv[1];

    int sock;
    struct sockaddr_in target_address;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Scanning ports on %s...\n", target_ip);

    // Start scanning ports
    for(int port = MIN_PORT; port <= MAX_PORT; port++) {

        // Set target_address values
        target_address.sin_addr.s_addr = inet_addr(target_ip);
        target_address.sin_family = AF_INET;
        target_address.sin_port = htons(port);

        // Connect to port
        int connected = connect(sock, (struct sockaddr *)&target_address, sizeof(target_address));

        if(connected == 0) {
            printf("Port %d is open\n", port);
        } else {
            // Uncomment for verbose output
            // printf("Port %d is closed\n", port);
        }
    }

    printf("Port scan done.\n");

    close(sock);

    return 0;
}