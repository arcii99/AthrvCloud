//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT_START 1
#define PORT_END 65535

bool is_open_port(const char* ip_address, int port){
    int sockid = socket(AF_INET, SOCK_STREAM, 0);
    if(sockid < 0){
        perror("Socket error. Exiting...");
        exit(1);
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip_address);
    address.sin_port = htons(port);

    if(connect(sockid, (struct sockaddr *)&address, sizeof(address)) == 0){
        close(sockid);
        return true;
    }
    close(sockid);
    return false;
}

void print_open_ports(const char* ip_address){
    printf("Scanning ports of host %s...\n", ip_address);
    for(int port=PORT_START; port<=PORT_END; port++){
        if(is_open_port(ip_address, port)){
            printf("%d is open.\n", port);
        }
    }
    printf("Scan completed.\n");
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }
    const char* ip_address = argv[1];
    print_open_ports(ip_address);
    return 0;
}