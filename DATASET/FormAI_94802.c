//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_PORTS 100

typedef struct {
    unsigned short port;
    int sock_descriptor;
} Port;

void *open_port(void *arg);

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Usage: ./wireless_scanner IP_ADDRESS\n");
        exit(1);
    }

    char *ip_address = argv[1];
    pthread_t threads[MAX_PORTS];
    Port ports[MAX_PORTS];
    int open_ports[MAX_PORTS];
    int num_open_ports = 0;

    printf("Scanning %s...\n", ip_address);

    for (int i = 0; i < MAX_PORTS; i++) {
        ports[i].port = i;
        ports[i].sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = inet_addr(ip_address);
        address.sin_port = htons(i);

        int result = connect(ports[i].sock_descriptor, (struct sockaddr *)&address, sizeof(address));
        if (result == 0) {
            open_ports[num_open_ports] = i;
            num_open_ports++;
            pthread_create(&threads[i], NULL, open_port, &ports[i]);
        } else {
            close(ports[i].sock_descriptor);
        }
    }

    for (int i = 0; i < num_open_ports; i++) {
        pthread_join(threads[open_ports[i]], NULL);
    }

    printf("Scanning complete. Found %d open ports.\n", num_open_ports);

    return 0;
}

void *open_port(void *arg) {
    Port port = *(Port *)arg;

    printf("Port %d is open.\n", port.port);
    close(port.sock_descriptor);
    pthread_exit(NULL);
}