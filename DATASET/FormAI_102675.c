//FormAI DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    int sock_descriptor;
    int error_flag;
    struct sockaddr_in target_address;
    socklen_t address_length;
    struct hostent *target_host;
    char *target_ip;
    int port;

    target_ip = argv[1];

    target_host = gethostbyname(target_ip);
    if(target_host == NULL ) {
        printf("Error - Invalid Target IP: %s\n", target_ip);
        exit(1);
    }

    printf("Scanning IP Address: %s\n", target_ip);

    for(port = 1; port <= MAX_PORT; port++) {

        sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);

        memset(&target_address, 0x00, sizeof(target_address));
        target_address.sin_family = AF_INET;
        target_address.sin_addr = *((struct in_addr *)target_host->h_addr);
        target_address.sin_port = htons(port);

        error_flag = connect(sock_descriptor, (struct sockaddr *)&target_address, sizeof(target_address));

        if(error_flag >= 0) {
            printf("Port %d - Open\n", port);
        }
        close(sock_descriptor);
    }

    return 0;
}