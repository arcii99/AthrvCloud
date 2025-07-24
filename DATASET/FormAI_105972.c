//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

void printMAC(unsigned char *addr) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
}

void printIP(int ip) {
    printf("%d.%d.%d.%d\n", (ip & 0xFF), (ip >> 8 & 0xFF), (ip >> 16 & 0xFF), (ip >> 24 & 0xFF));
}

int main(int argc, char *argv[]) {
    int sock;
    struct ifreq ifr;
    struct sockaddr_in sin;
    
    // Get socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    
    // Set interface to wlan0
    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ);
    
    // Get MAC address
    if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl");
        exit(1);
    }
    printf("MAC Address: ");
    printMAC((unsigned char *)ifr.ifr_hwaddr.sa_data);
    
    // Get IP address
    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl");
        exit(1);
    }
    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
    printf("IP Address: ");
    printIP(sin.sin_addr.s_addr);
    
    // Close socket
    close(sock);
}