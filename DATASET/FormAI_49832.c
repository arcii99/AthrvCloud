//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan an individual port
int scan_port(char* target_ip, int port) {
    struct sockaddr_in target_address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    target_address.sin_family = AF_INET;
    target_address.sin_addr.s_addr = inet_addr(target_ip);
    target_address.sin_port = htons(port);
    
    // Attempt to connect to target port
    if (connect(sock, (struct sockaddr *)&target_address, sizeof(target_address)) == 0) {
        // Port is open
        printf("Port %d is open!\n", port);
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <target_ip> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char* target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, target_ip);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(target_ip, port);
    }

    printf("Scan complete!\n");

    return 0;
}