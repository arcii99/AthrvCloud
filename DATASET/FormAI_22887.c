//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_INTERFACES 16

struct wireless_network {
    char ssid[256];
    char bssid[256];
    int frequency;
    int signal_level;
};

typedef struct wireless_network wireless_network_t;

int main() {
    printf("Welcome to C Wireless Network Scanner!\n\n");

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    struct ifreq ifaces[MAX_INTERFACES];
    struct ifconf ifconfig;
    ifconfig.ifc_len = sizeof(ifaces);
    ifconfig.ifc_req = ifaces;

    if (ioctl(sock_fd, SIOCGIFCONF, &ifconfig) == -1) {
        perror("Failed to get network interfaces");
        close(sock_fd);
        return 1;
    }

    int num_ifaces = ifconfig.ifc_len / sizeof(struct ifreq);
    printf("Found %d network interfaces:\n", num_ifaces);
    for (int i = 0; i < num_ifaces; i++) {
        printf("- %s\n", ifaces[i].ifr_name);
    }
    printf("\n");

    int on = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) == -1) {
        perror("Failed to enable broadcast for socket");
        close(sock_fd);
        return 1;
    }

    wireless_network_t networks[16];
    int num_networks = 0;

    for (int i = 0; i < num_ifaces; i++) {
        struct ifreq ifr;
        strncpy(ifr.ifr_name, ifaces[i].ifr_name, IFNAMSIZ);

        if (ioctl(sock_fd, SIOCGIFFLAGS, &ifr) == -1) {
            perror("Failed to get interface flags");
            continue;
        }

        if (!(ifr.ifr_flags & IFF_UP)) {
            continue;
        }

        struct sockaddr_in broadcast_address;
        memset(&broadcast_address, 0, sizeof(broadcast_address));
        broadcast_address.sin_family = AF_INET;
        broadcast_address.sin_port = htons(67);
        broadcast_address.sin_addr.s_addr = htonl(INADDR_BROADCAST);

        if (sendto(sock_fd, NULL, 0, 0, (struct sockaddr *)&broadcast_address, sizeof(broadcast_address)) == -1) {
            perror("Failed to send broadcast packet");
            continue;
        }

        unsigned char packet[1024];
        int length = recv(sock_fd, packet, sizeof(packet), 0);
        if (length == -1) {
            perror("Failed to receive packet");
            continue;
        }

        for (int j = 0; j < length; j++) {
            if (packet[j] == '\x00' && packet[j+1] == '\x25') {
                wireless_network_t network;

                int k = j+2;
                while (packet[k] != '\x00') {
                    network.ssid[k-j-2] = packet[k];
                    k++;
                }
                network.ssid[k-j-2] = '\0';

                memcpy(network.bssid, &packet[k+1], 6);

                network.frequency = ((int)packet[k+8] * 256 + (int)packet[k+9]);
                network.signal_level = (int)packet[k+10] - 256;

                networks[num_networks++] = network;
            }
        }
    }

    printf("Found %d wireless networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("- %s (BSSID: %02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx, Frequency: %d MHz, Signal Level: %d dBm)\n", networks[i].ssid, networks[i].bssid[0], networks[i].bssid[1], networks[i].bssid[2], networks[i].bssid[3], networks[i].bssid[4], networks[i].bssid[5], networks[i].frequency, networks[i].signal_level);
    }

    close(sock_fd);
    return 0;
}