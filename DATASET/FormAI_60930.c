//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_IP_LEN 16

int main(){
    int sock_fd;
    struct sockaddr_in sin;
    char ip_address[MAX_IP_LEN];

    // create socket
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Socket creation failed with error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // set up the server address
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80); // scanning for networks on port 80
    sin.sin_addr.s_addr = inet_addr("192.168.0.1");

    // scan the network
    printf("Scanning the network...\n");

    for(int i=1; i<=254; i++){
        snprintf(ip_address, MAX_IP_LEN, "192.168.0.%d", i);
        sin.sin_addr.s_addr = inet_addr(ip_address);

        if(connect(sock_fd, (struct sockaddr *)&sin, sizeof(sin)) == 0){
            printf("%s - Network is available and responsive\n", ip_address);
        }
    }

    printf("Scanning complete.\n");

    close(sock_fd);

    return EXIT_SUCCESS;
}