//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<ifaddrs.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>

#define MAX_INTERFACE_NAME_LEN 128

void print_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    struct ifaddrs *ifaddr, *ifa;

    if (getifaddrs(&ifaddr) == -1) {
        print_error("Getifaddrs error");
    }

    char ipstr[INET_ADDRSTRLEN];
    int count = 1;

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        int family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            struct sockaddr_in *s4 = (struct sockaddr_in *) ifa->ifa_addr;
            inet_ntop(family, (void *) &(s4->sin_addr), ipstr, sizeof(ipstr));
            printf("%d) Interface Name :%-25s IP Address: %s\n", count, ifa->ifa_name, ipstr);
            count++;
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}