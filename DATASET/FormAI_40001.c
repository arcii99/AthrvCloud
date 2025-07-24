//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

int main() {
    int sock;
    struct iwreq wreq;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        printf("Error: Could not create socket!\n");
        return 1;
    }

    strncpy(wreq.ifr_name, "wlan0", IFNAMSIZ);

    if (ioctl(sock, SIOCGIWNAME, &wreq) == -1) {
        printf("Error: Could not retrieve wireless name!\n");
        return 1;
    }

    printf("Wireless Network Interface: %s\n", wreq.ifr_name);

    if (ioctl(sock, SIOCGIWFREQ, &wreq) == -1) {
        printf("Error: Could not retrieve wireless frequency!\n");
        return 1;
    }

    printf("Wireless Frequency: %d feet\n", wreq.u.freq.m);

    if (ioctl(sock, SIOCGIWMODE, &wreq) == -1) {
        printf("Error: Could not retrieve wireless mode!\n");
        return 1;
    }

    printf("Wireless Mode: ");

    switch(wreq.u.mode) {
        case IW_MODE_AUTO:
            printf("Auto\n");
            break;
        case IW_MODE_ADHOC:
            printf("Ad-hoc\n");
            break;
        case IW_MODE_INFRA:
            printf("Infrastructure\n");
            break;
        case IW_MODE_MASTER:
            printf("Master\n");
            break;
        case IW_MODE_REPEAT:
            printf("Repeater\n");
            break;
        case IW_MODE_SECOND:
            printf("Secondary\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    close(sock);
    return 0;
}