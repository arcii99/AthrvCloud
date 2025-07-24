//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACE_NAME 32
#define MAX_MAC_ADDR_LEN  18

typedef struct {
    char if_name[MAX_INTERFACE_NAME];
    unsigned char mac_address[MAX_MAC_ADDR_LEN];
} interface_t;

interface_t *get_interfaces(int *count) {
    struct ifconf conf;
    struct ifreq *ifr;
    int sock;
    int num_ifaces;
    int i;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return NULL;
    }

    conf.ifc_req = NULL;
    conf.ifc_len = 0;
    if (ioctl(sock, SIOCGIFCONF, &conf) < 0) {
        perror("ioctl(SIOGIFCONF)");
        close(sock);
        return NULL;
    }

    ifr = (struct ifreq *) malloc(conf.ifc_len);
    if (ifr == NULL) {
        perror("malloc");
        close(sock);
        return NULL;
    }

    conf.ifc_req = ifr;
    if (ioctl(sock, SIOCGIFCONF, &conf) < 0) {
        perror("ioctl(SIOGIFCONF)");
        close(sock);
        free(ifr);
        return NULL;
    }

    num_ifaces = conf.ifc_len / sizeof(struct ifreq);

    if (num_ifaces == 0) {
        printf("No interfaces found!\n");
        close(sock);
        free(ifr);
        return NULL;
    }

    interface_t *interfaces = (interface_t *) malloc(sizeof(interface_t) * num_ifaces);
    if (interfaces == NULL) {
        perror("malloc");
        close(sock);
        free(ifr);
        return NULL;
    }

    for (i = 0; i < num_ifaces; i++) {
        strcpy(interfaces[i].if_name, ifr[i].ifr_name);

        if (ioctl(sock, SIOCGIFHWADDR, &ifr[i]) < 0) {
            perror("ioctl(SIOCGIFHWADDR)");
            close(sock);
            free(ifr);
            free(interfaces);
            return NULL;
        }

        snprintf((char *) interfaces[i].mac_address, MAX_MAC_ADDR_LEN, "%02x:%02x:%02x:%02x:%02x:%02x",
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[0],
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[1],
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[2],
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[3],
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[4],
                 (unsigned char) ifr[i].ifr_hwaddr.sa_data[5]);
    }

    close(sock);
    free(ifr);

    *count = num_ifaces;
    return interfaces;
}

void print_interfaces(interface_t *interfaces, int count) {
    int i;
    printf("%-16s %-18s\n", "Interface Name", "MAC Address");
    for (i = 0; i < count; i++) {
        printf("%-16s %-18s\n", interfaces[i].if_name, interfaces[i].mac_address);
    }
}

int main(int argc, char **argv) {
    int count;
    interface_t *interfaces;

    interfaces = get_interfaces(&count);
    if (interfaces == NULL) {
        printf("Error getting interface list!\n");
        return -1;
    }

    print_interfaces(interfaces, count);
    free(interfaces);

    return 0;
}