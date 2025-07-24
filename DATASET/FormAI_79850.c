//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535 // maximum number of ports to scan
#define TIMEOUT 5 // number of seconds to wait for a response

void scanPort(char *ip, int port);
int getSocket();
bool isPortOpen(int sock);
void usage(char *name);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    
    char *ip = argv[1];
    
    for (int i = 1; i <= MAX_PORTS; i++) {
        scanPort(ip, i);
    }
    
    return 0;
}

void scanPort(char *ip, int port) {
    int sock = getSocket();
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(ip);
    
    if (connect(sock, (struct sockaddr *)&dest, sizeof(dest)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
    
    close(sock);
}

int getSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }
    return sock;
}

bool isPortOpen(int sock) {
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        return false;
    }
    
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        return false;
    }
    
    return true;
}

void usage(char *name) {
    printf("Usage: %s <ip-address>\n", name);
}