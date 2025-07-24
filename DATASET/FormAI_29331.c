//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TIMEOUT 1
#define MAXPORT 65535

/**
 * Performs a TCP port scan of a given host.
 * @param host The IP address or hostname of the host to scan.
 * @param scanPorts An array of integers representing the ports to scan.
 * @param numPorts The number of ports in the scanPorts array.
 * @param openPorts An array to hold the results of the scan.
 * @param timeout The number of seconds to wait before timing out each port scan.
 * @return 0 on success, -1 on error.
 */
int tcp_port_scan(const char* host, int* scanPorts, int numPorts, int* openPorts, int timeout)
{
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    struct sockaddr_in sa;
    int sock, status, i;
    for(i = 0; i < numPorts; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            return -1;
        }
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = inet_addr(host);
        sa.sin_port = htons(scanPorts[i]);
        status = connect(sock, (struct sockaddr*)&sa, sizeof(sa));
        if(status < 0) {
            close(sock);
        } else {
            openPorts[i] = scanPorts[i];
            close(sock);
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    if(argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }
    const char* host = argv[1];
    int scanPorts[MAXPORT], openPorts[MAXPORT];
    memset(scanPorts, 0, sizeof scanPorts);
    memset(openPorts, 0, sizeof openPorts);
    int i;
    for(i = 0; i < MAXPORT; i++) {
        scanPorts[i] = i + 1;
    }
    int numPorts = sizeof(scanPorts) / sizeof(scanPorts[0]);
    int timeout = TIMEOUT;
    if(tcp_port_scan(host, scanPorts, numPorts, openPorts, timeout) < 0) {
        printf("Error scanning host %s\n", host);
        exit(1);
    }
    printf("Open ports on %s are:\n", host);
    for(i = 0; i < numPorts; i++) {
        if(openPorts[i] != 0) {
            printf("%d\n", openPorts[i]);
        }
    }
    exit(0);
}