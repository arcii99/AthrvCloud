//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_DEVICES 1000

struct Device {
    char name[20];
    char ip[20];
};

int main() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];
    struct Device devices[MAX_DEVICES];
    int device_count = 0;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, n = 0; ifa != NULL && n < MAX_DEVICES; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET || family == AF_INET6) {
            s = getnameinfo(ifa->ifa_addr,
                    (family == AF_INET) ? sizeof(struct sockaddr_in) :
                    sizeof(struct sockaddr_in6),
                    host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }

            if (family == AF_INET && strcmp(ifa->ifa_name, "lo") != 0) {
                memset(devices[device_count].name, 0, sizeof(devices[device_count].name));
                memset(devices[device_count].ip, 0, sizeof(devices[device_count].ip));
                strcpy(devices[device_count].name, ifa->ifa_name);
                strcpy(devices[device_count].ip, host);
                device_count++;
            }
        }
    }

    freeifaddrs(ifaddr);

    printf("Device Name\t IP Address\n");
    printf("--------------------\t -------------\n");

    for (int i = 0; i < device_count; i++) {
        printf("%s\t\t %s\n", devices[i].name, devices[i].ip);
    }

    return 0;
}