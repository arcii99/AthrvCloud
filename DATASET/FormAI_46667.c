//FormAI DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT_NUM 65535

bool check_port_open(char* host, int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock == -1) {
        printf("Failed to create socket.\n");
        exit(1);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(host);
    address.sin_port = htons(port);
    
    int result = connect(sock, (struct sockaddr*)&address, sizeof(address));
    close(sock);
    
    if (result == 0) {
        return true;
    }
    
    return false;
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter a hostname.\n");
        exit(1);
    }
    
    char* host = argv[1];
    printf("Scanning ports on %s...\n", host);
    
    for (int port = 1; port <= MAX_PORT_NUM; port++) {
        if (check_port_open(host, port)) {
            printf("%d is open.\n", port);
        }
    }
    
    printf("Port scan complete.\n");
    return 0;
}