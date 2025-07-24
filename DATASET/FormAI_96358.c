//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *target = argv[1];

    // Create a socket for the scan
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Initialize the sockaddr_in structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1); // Start scanning at port 1
    inet_pton(AF_INET, target, &addr.sin_addr);

    // Start scanning all open ports on the host
    while (addr.sin_port < htons(65535)) {
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", ntohs(addr.sin_port));
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("Failed to create socket");
                return 1;
            }
        }
        addr.sin_port = htons(ntohs(addr.sin_port) + 1);
    }

    printf("Scan complete\n");
    return 0;
}