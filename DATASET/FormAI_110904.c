//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ifaddrs.h>

#define PORT 8080

void *scanner(void *arg) {
    struct ifaddrs *ifaddr, *ifa;
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;

    if (net_socket < 0) {
        perror("socket creation failed");
        pthread_exit(NULL); 
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr("192.168.1.255"); 
    address.sin_port = htons(PORT); 

    if (bind(net_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        pthread_exit(NULL); 
    }

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        pthread_exit(NULL); 
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        struct sockaddr_in *ip = (struct sockaddr_in *)ifa->ifa_addr;
        char *interface = ifa->ifa_name;

        if (setsockopt(net_socket, SOL_SOCKET, SO_BINDTODEVICE, interface, strlen(interface)) < 0) {
            perror("setsockopt SO_BINDTODEVICE failed");
            pthread_exit(NULL); 
        }

        if (sendto(net_socket, "Hello, World!", 13, 0, (struct sockaddr *)&address, sizeof(address)) < 13) {
            printf("Unable to send packet on interface '%s'\n", interface);
        } else {
            printf("Packet sent on interface '%s'\n", interface);
        }
    }

    freeifaddrs(ifaddr);
    close(net_socket);
    pthread_exit(NULL); 
}

int main() {
    pthread_t tid;

    if (pthread_create(&tid, NULL, scanner, NULL) != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE); 
    }

    pthread_join(tid, NULL);
    return 0;
}