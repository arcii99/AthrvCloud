//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if(argc < 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }

    int sock; 
    struct sockaddr_in target;
    int start_port = 1;
    int end_port = 65535;

    // Create socket 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return -1;
    }
    printf("Socket created!\n");

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // Scan all the ports from start_port to end_port 
    for(int port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Connect to the specified ip address and port 
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
            continue;
        }
        printf("Port %d is open\n", port);
        close(sock);
        // Create new socket for next scan 
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Could not create socket");
            return -1;
        }
    }

    printf("Scan complete!\n");
    close(sock);
    return 0;
}