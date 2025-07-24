//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_QUALITY 100
#define MAX_STRENGTH 70

void analyze_wifi_signal_strength(int sockfd, struct iw_statistics* iwstats, int* quality, int* strength) {
    char ifname[IFNAMSIZ];
    if (ioctl(sockfd, SIOCGIFNAME, ifname) < 0) {
        perror("ioctl");
        return;
    }

    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, ifname, IFNAMSIZ);

    wrq.u.data.pointer = (caddr_t) iwstats;
    wrq.u.data.length = sizeof(struct iw_statistics);
    wrq.u.data.flags = 1;

    if (ioctl(sockfd, SIOCGIWSTATS, &wrq) < 0) {
        perror("ioctl");
        return;
    }

    if (!iwstats->qual.updated || !iwstats->qual.qual) {
        return;
    }

    *quality = (int) (((float) iwstats->qual.qual) / MAX_QUALITY * 100);
    *strength = (int) (iwstats->qual.level - MAX_STRENGTH);
}

int main(int argc, char** argv) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    char* ifname;
    if (argc > 1) {
        ifname = argv[1];
    } else {
        ifname = "wlan0";
    }

    int quality, strength;
    struct iw_statistics iwstats;
    memset(&iwstats, 0, sizeof(iwstats));
    analyze_wifi_signal_strength(sockfd, &iwstats, &quality, &strength);

    printf("Wi-Fi Signal Strength Analyzer:\n");
    printf("Interface: %s\n", ifname);
    printf("Quality: %d%%\n", quality);
    printf("Strength: %ddBm\n", strength);

    close(sockfd);
    return 0;
}