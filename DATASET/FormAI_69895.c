//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <ip_address>\n",argv[0]);
        return 1;
    }

    char *target_ip_address = argv[1];
    int low_port,high_port;

    printf("Enter the lowest and highest port numbers to scan (e.g. 1 65535):\n");
    scanf("%d %d",&low_port,&high_port);
    printf("Scanning ports between %d and %d on %s\n",low_port,high_port,target_ip_address);

    int i,j;
    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_addr.s_addr = inet_addr(target_ip_address);

    for (i = low_port; i <= high_port; i++) {
        int scanner_socket = socket(AF_INET, SOCK_STREAM, 0);
        target_address.sin_port = htons(i);
        int connection_status = connect(scanner_socket, (struct sockaddr *)&target_address, sizeof(target_address));
        if (connection_status == -1) {
            continue;
        } else {
            printf("Port %d is open\n",i);
        }
        close(scanner_socket);
    }
    return 0;
}