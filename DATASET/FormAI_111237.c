//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 64
#define MAX_ADAPTER_ADDRESS_LENGTH 8
#define WLAN_INET_ADDR_HDRLEN 4

struct Intf {
    char intf_name[IFNAMSIZ];
    char mac_addr[MAX_ADAPTER_ADDRESS_LENGTH];
    int has_ip;
    struct in_addr ip_addr;
    struct Intf *next;
};

struct Intf *interface_list_head = NULL;

struct Intf *populate_interface_list();
void free_interface_list(struct Intf *interface_list_head);
int get_wlan_inet_addr(struct Intf *interface);
void display_interface_list(struct Intf *interface_list_head);

int main(int argc, char *argv[]) {
    struct Intf *interface = NULL;

    interface = populate_interface_list();
    if (!interface) {
        printf("Error: Unable to populate the interface list.\n");
        exit(1);
    }

    display_interface_list(interface);

    free_interface_list(interface);
    return 0;
}

/*
 * This function populates the interface list and returns the head of the list.
 */
struct Intf *populate_interface_list() {
    struct ifreq ifr;
    struct ifconf ifc;
    struct Intf *interface_list = NULL;
    struct Intf *interface = NULL;
    char *buf = NULL;
    int sd = 0;
    int i = 0;
    int len = 0;
    int num_interfaces = 0;

    memset(&ifr, 0, sizeof(ifr));
    memset(&ifc, 0, sizeof(ifc));

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd == -1) {
        printf("Error: socket creation failed\n");
        return NULL;
    }

    /* get all interfaces */
    ifc.ifc_buf = NULL;
    ifc.ifc_len = 0;
    if (ioctl(sd, SIOCGIFCONF, &ifc) == -1) {
        printf("Error: ioctl failed\n");
        close(sd);
        return NULL;
    }

    buf = (char *) malloc(ifc.ifc_len);
    if (!buf) {
        printf("Error: memory allocation failed\n");
        close(sd);
        return NULL;
    }

    memset(buf, 0, ifc.ifc_len);
    ifc.ifc_buf = buf;
    if (ioctl(sd, SIOCGIFCONF, &ifc) == -1) {
        printf("Error: ioctl failed\n");
        close(sd);
        free(buf);
        return NULL;
    }

    num_interfaces = ifc.ifc_len / sizeof(struct ifreq);
    printf("Number of interfaces: %d\n", num_interfaces);

    for (i = 0; i < num_interfaces; i++) {
        memset(&ifr, 0, sizeof(ifr));
        memcpy(&ifr, &ifc.ifc_req[i], sizeof(ifr));

        /* get mac address */
        if (ioctl(sd, SIOCGIFHWADDR, &ifr) == -1) {
            printf("Error: getting mac address failed for interface: %s\n", ifr.ifr_name);
        }
        else {
            printf("MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                   ifr.ifr_hwaddr.sa_data[0],
                   ifr.ifr_hwaddr.sa_data[1],
                   ifr.ifr_hwaddr.sa_data[2],
                   ifr.ifr_hwaddr.sa_data[3],
                   ifr.ifr_hwaddr.sa_data[4],
                   ifr.ifr_hwaddr.sa_data[5]);
        }

        /* get inet address */
        memset(&ifr, 0, sizeof(ifr));
        memcpy(&ifr.ifr_name, &ifc.ifc_req[i].ifr_name, sizeof(ifr.ifr_name));
        if (ioctl(sd, SIOCGIFADDR, &ifr) == -1) {
            /* interface does not have an address */
            printf("Interface %s does not have an IP address.\n", ifr.ifr_name);
        }
        else {
            interface = (struct Intf *) malloc(sizeof(struct Intf));
            if (!interface) {
                printf("Error: memory allocation failed\n");
                free_interface_list(interface_list);
                close(sd);
                free(buf);
                return NULL;
            }

            memset(interface, 0, sizeof(struct Intf));
            memset(&ifr, 0, sizeof(ifr));
            memcpy(&interface->intf_name, &ifc.ifc_req[i].ifr_name, sizeof(interface->intf_name));
            strncpy(interface->mac_addr, (char *) ifr.ifr_addr.sa_data, MAX_ADAPTER_ADDRESS_LENGTH);
            interface->has_ip = 1;
            memcpy(&interface->ip_addr, &((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr, sizeof(struct in_addr));
            interface->next = interface_list;
            interface_list = interface;
        }
    }

    free(buf);
    close(sd);

    return interface_list;
}

/*
 * This function frees the memory used for the interface list.
 */
void free_interface_list(struct Intf *interface_list_head) {
    struct Intf *interface = NULL;

    while (interface_list_head) {
        interface = interface_list_head;
        interface_list_head = interface->next;
        free(interface);
    }
}

/*
 * This function calculates the wlan inet address.
 */
int get_wlan_inet_addr(struct Intf *interface) {
    int addr = 0;
    char *intf_addr = NULL;

    intf_addr = inet_ntoa(interface->ip_addr);
    if (!intf_addr) {
        return 0;
    }

    sscanf(intf_addr, "%d.%*d.%*d.%*d", &addr);
    return htonl(addr) + htonl(WLAN_INET_ADDR_HDRLEN << 24);
}

/*
 * This function displays the interface list.
 */
void display_interface_list(struct Intf *interface_list_head) {
    struct Intf *interface = interface_list_head;
    int addr = 0;

    while (interface) {
        printf("\nEthernet interface name: %s\n", interface->intf_name);
        printf("MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
               interface->mac_addr[0],
               interface->mac_addr[1],
               interface->mac_addr[2],
               interface->mac_addr[3],
               interface->mac_addr[4],
               interface->mac_addr[5]);
        if (interface->has_ip) {
            printf("IP address: %s\n", inet_ntoa(interface->ip_addr));
            addr = get_wlan_inet_addr(interface);
            printf("WLAN inet address: %d.%d.%d.%d\n",
                   (addr >> 24) & 0xFF,
                   (addr >> 16) & 0xFF,
                   (addr >> 8) & 0xFF,
                   addr & 0xFF);
        }
        else {
            printf("Interface %s does not have an IP address.\n", interface->intf_name);
        }
        interface = interface->next;
    }
}