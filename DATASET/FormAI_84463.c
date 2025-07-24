//FormAI DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP_ADDRESS "127.0.0.1" //Enter the target IP address here
#define PORT_START 1 //Enter starting port number here
#define PORT_END 1024 //Enter ending port number here

int main() {
    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(PORT_START);
    target_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    memset(&(target_addr.sin_zero), '\0', 8);

    printf("Scanning target %s...\n", IP_ADDRESS);

    for(int i = PORT_START; i <= PORT_END; i++) {
        target_addr.sin_port = htons(i);

        //Connect to target port
        int conn_status = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if(conn_status == 0) {
            printf("[+] Port %d is open!\n", i);
        }
    }

    printf("[=] Scan complete.\n");

    return 0;
}