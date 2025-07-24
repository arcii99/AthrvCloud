//FormAI DATASET v1.0 Category: Port Scanner ; Style: complex
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in host_address;
    memset(&host_address, 0, sizeof(host_address));

    if (inet_pton(AF_INET, argv[1], &host_address.sin_addr) <= 0) {
        perror("Address not valid");
        exit(EXIT_FAILURE);
    }

    host_address.sin_family = AF_INET;
      
    int scanned_ports[65535];
    int port;
    for (port = 1; port <= 65535; port++) {
        memset(&host_address.sin_zero, 0, sizeof(host_address.sin_zero));
        host_address.sin_port = htons(port);
        if (connect(socket_descriptor, (struct sockaddr *)&host_address , sizeof(host_address)) < 0) {
            scanned_ports[port] = 0;
        } else {
            scanned_ports[port] = 1;
        }
        close(socket_descriptor);
    }

    printf("Opened Ports on %s:\n", argv[1]);
    for(int i = 1; i <= 65535; i++) {
        if(scanned_ports[i] == 1) {
            printf("%d\n",i);
        }
    }

    return(0);
}