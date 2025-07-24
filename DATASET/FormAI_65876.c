//FormAI DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT_MS 500

void printBanner();
bool isPortOpen(const char* ipAddress, int port);

int main(int argc, char *argv[]) {
    printBanner();

    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return -1;
    }
  
    printf("Scanning ports on IP address: %s\n", argv[1]);
  
    // Scan for the first 1024 ports
    int i;
    for (i = 1; i <= 1024; i++) {
        if (isPortOpen(argv[1], i)) {
            printf("%d/tcp  open\n", i);
        }
    }
  
    printf("\nScan complete!\n");
  
  return 0;
}

// prints banner message
void printBanner() {
    printf("********************************************\n");
    printf("        Welcome to the C Port Scanner!\n");
    printf("********************************************\n");
}

// check if port is open on given ip address
bool isPortOpen(const char* ipAddress, int port) {
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ipAddress);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (!sock) {
        perror("socket");
        exit(1);
    }

    // set timeout for connection request
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_MS / 1000;
    timeout.tv_usec = TIMEOUT_MS % 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server , sizeof(server)) < 0) {
        return false;
    }
  
    close(sock);
    return true;
}