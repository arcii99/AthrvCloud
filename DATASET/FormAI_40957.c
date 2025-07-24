//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_IP_LEN INET6_ADDRSTRLEN

int main() {
    struct ifaddrs *ifaddr, *ifa;
    char ipaddr[MAX_IP_LEN], hostname[MAX_HOSTNAME_LEN];

    // Get list of network interfaces
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Loop through network interface list
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        // Skip interfaces without an IP address
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        // Get hostname
        getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr), hostname, MAX_HOSTNAME_LEN, NULL, 0, NI_NAMEREQD);

        // Get IP address
        if (ifa->ifa_addr->sa_family == AF_INET) {
            inet_ntop(AF_INET, &(((struct sockaddr_in*)ifa->ifa_addr)->sin_addr), ipaddr, MAX_IP_LEN);
            printf("IPv4 Address: %s\tHostname: %s\n", ipaddr, hostname);
        } else if (ifa->ifa_addr->sa_family == AF_INET6) {
            inet_ntop(AF_INET6, &(((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr), ipaddr, MAX_IP_LEN);
            printf("IPv6 Address: %s\tHostname: %s\n", ipaddr, hostname);
        }
    }

    // Free memory
    freeifaddrs(ifaddr);

    return 0;
}