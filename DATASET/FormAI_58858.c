//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(char *ip_addr, int port){
    // Creating a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        return;
    }

    // Storing the target IP and port
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_addr);
    target.sin_port = htons(port);

    // Connecting to the target
    int conn = connect(sock, (struct sockaddr *)&target, sizeof(target));
    if (conn == 0){
        printf("Port %d: open \n", port);
    } else {
        printf("Port %d: closed \n", port);
    }
    close(sock);
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("Usage: ./port_scanner IPADDRESS \n");
        return 0;
    }

    char *ip_addr = argv[1];
    int start_port = 1;
    int end_port = 1024;

    printf("Scanning ports on %s\n", ip_addr);

    for (int port = start_port; port <= end_port; port++){
        scan_port(ip_addr, port);
    }
    return 0;
}