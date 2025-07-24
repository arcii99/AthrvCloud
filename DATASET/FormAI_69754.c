//FormAI DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PORT_NUM 65535

void port_scan(char* ip_address, int starting_port, int ending_port);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: ./port_scanner <ip_address>\n");
        return -1;
    }
    char* ip_address = argv[1];

    printf("Port scanner starting for %s...\n", ip_address);
    
    port_scan(ip_address, 1, MAX_PORT_NUM);

    printf("Port scanning finished for %s\n", ip_address);

    return 0;
}

void port_scan(char* ip_address, int starting_port, int ending_port) {
    struct sockaddr_in server;
    int sock, cur_port;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    for(cur_port = starting_port; cur_port <= ending_port; cur_port++) {
        server.sin_port = htons(cur_port);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            printf("Error creating socket\n");
            continue;
        }
        if(connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", cur_port);
        }
        close(sock);
    }
}