//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/wireless.h>

#define WL_DEVICE "wlan0"

int main() {
    int fd;
    struct iwreq wrq;
    char buffer[IW_ESSID_MAX_SIZE];

    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, WL_DEVICE, IFNAMSIZ);

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    wrq.u.essid.pointer = buffer;
    wrq.u.essid.length = IW_ESSID_MAX_SIZE;
    if (ioctl(fd, SIOCGIWESSID, &wrq) < 0) {
        perror("ioctl failed");
        exit(EXIT_FAILURE);
    }

    printf("Wireless Network Scanner\n");
    printf("========================\n");
    printf("Network Name: %s\n", buffer);

    close(fd);
    return 0;
}