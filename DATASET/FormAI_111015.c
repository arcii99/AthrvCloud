//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void scan(int port_num) {
    struct sockaddr_in target_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port_num);
    target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int connected = connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if(connected == 0) {
        printf("Port %d is open\n", port_num);
    }
    close(sock);
}

int main() {
    printf("Starting C port scanner...\n");
    for(int i=1; i<=65535; i++) {
        scan(i);
    }
    printf("Scan complete!\n");
    return 0;
}