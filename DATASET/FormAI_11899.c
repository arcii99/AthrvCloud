//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

#define MAX_INTERFACES 64

void print_signal_strength(char *interface) {
    int sock;
    struct iwreq request;
    char *ssid;
    char *mac;
    int frequency;
    int signal_strength;

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&request, 0, sizeof(struct iwreq));
    strncpy(request.ifr_name, interface, IFNAMSIZ);

    if (ioctl(sock, SIOCGIWESSID, &request) == -1) {
        perror("ioctl");
        exit(1);
    }

    ssid = (char *) request.u.essid.pointer;

    if (ioctl(sock, SIOCGIWFREQ, &request) == -1) {
        perror("ioctl");
        exit(1);
    }

    frequency = request.u.freq.m;

    if (ioctl(sock, SIOCGIWAP, &request) == -1) {
        perror("ioctl");
        exit(1);
    }

    mac = (char *) request.u.ap_addr.sa_data;

    if (ioctl(sock, SIOCGIWSTATS, &request) == -1) {
        perror("ioctl");
        exit(1);
    }

    signal_strength = request.u.qual.level;

    printf("%-15s %-15s %-15d %-15d\n", interface, ssid, frequency, signal_strength);
}

int main(void) {
    int i;
    int interfaces;
    int skfd;
    struct iwreq wrq;
    struct ifreq ifr[MAX_INTERFACES];

    if ((skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    strncpy(wrq.ifr_name, "mon0", IFNAMSIZ);

    if (ioctl(skfd, SIOCGIFCONF, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    interfaces = sizeof(ifr) / sizeof(ifr[0]);

    printf("%-15s %-15s %-15s %-15s\n", "Interface", "SSID", "Frequency", "Signal Strength");
    for (i = 0; i < interfaces; i++) {
        int sock;
        struct iwreq request;
        char *interface = ifr[i].ifr_name;

        if (ioctl(skfd, SIOCGIFFLAGS, &ifr[i]) == -1) {
            perror("ioctl");
            exit(1);
        }

        if (ifr[i].ifr_flags & IFF_UP) {
            print_signal_strength(interface);
        }
    }

    close(skfd);
    return 0;
}