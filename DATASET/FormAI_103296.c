//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <target ip>\n", argv[0]);
        return 1;
    }
    
    char *target_ip = argv[1];
    int start_port = 1;
    int end_port = 65535;
    
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    for(int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            perror("socket() failed");
            return 1;
        }
        
        target_addr.sin_port = htons(port);
        
        if(connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", port);
        }
        
        close(sock);
    }
    
    return 0;
}