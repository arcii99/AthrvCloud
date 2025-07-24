//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_INTERFACES 64
#define MAX_IP_ADDR 32

typedef struct iface {
    char name[IFNAMSIZ];
    struct in_addr ip_addrs[MAX_IP_ADDR];
    int num_ip_addrs;
} iface_t;

int get_ifaces(iface_t *ifaces) {
    struct ifreq ifr;
    struct ifconf ifc;
    char buf[2048];
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl");
        exit(1);
    }
    struct ifreq *it = ifc.ifc_req;
    const struct ifreq *const end = it + (ifc.ifc_len / sizeof(struct ifreq));
    for (; it != end; ++it) {
        strcpy(ifr.ifr_name, it->ifr_name);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            if (! (ifr.ifr_flags & IFF_LOOPBACK)) {
                iface_t iface;
                strncpy(iface.name, it->ifr_name, IFNAMSIZ);
                if (ioctl(sock, SIOCGIFADDR, &ifr) != -1) {
                    struct sockaddr_in *addr = (struct sockaddr_in *) &ifr.ifr_addr;
                    iface.num_ip_addrs = 1;
                    memcpy(&iface.ip_addrs[0], &addr->sin_addr, sizeof(addr->sin_addr));
                    int idx = 1;
                    while (idx < MAX_IP_ADDR && ioctl(sock, SIOCGIFADDR, &ifr) != -1) {
                        addr = (struct sockaddr_in *) &ifr.ifr_addr;
                        memcpy(&iface.ip_addrs[idx], &addr->sin_addr, sizeof(addr->sin_addr));
                        ++iface.num_ip_addrs;
                        ++idx;
                    }
                }
                *ifaces = iface;
                ++ifaces;
            }
        } else {
            perror("ioctl");
            exit(1);
        }
    }
    close(sock);
    return ifaces - ifaces;
}

int main(int argc, char **argv) {
    iface_t ifaces[MAX_INTERFACES];
    int num_ifaces = get_ifaces(ifaces);
    printf("Number of interfaces: %d\n", num_ifaces);
    for (int i = 0; i < num_ifaces; ++i) {
        printf("Interface %s:\n", ifaces[i].name);
        for (int j = 0; j < ifaces[i].num_ip_addrs; ++j) {
            printf("%-15s%s\n", "IP Address:", inet_ntoa(ifaces[i].ip_addrs[j]));
        }
    }
    return 0;
}