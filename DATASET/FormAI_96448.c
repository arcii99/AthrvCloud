//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <linux/wireless.h>

void print_wireless_info(const char *ifname) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0); // create socket
    if (sock < 0) {
        perror("Failed to create socket");
        return;
    }
    struct iwreq wreq;
    wreq.u.data.pointer = NULL;
    wreq.u.data.length = 0;
    wreq.u.data.flags = 0;
    strncpy(wreq.ifr_name, ifname, IFNAMSIZ); // copy interface name
    if (ioctl(sock, SIOCGIWNAME, &wreq) == -1) { // check if Wireless Extension device present
        perror("This device does not have wireless extensions");
        return;
    }
    if (ioctl(sock, SIOCGIWESSID, &wreq) == -1) { // get wireless ESSID
        perror("Failed to get ESSID");
        return;
    }
    printf("Wireless ESSID: %s\n", wreq.u.essid.pointer);
    if (ioctl(sock, SIOCGIWMODE, &wreq) == -1) { // get wireless mode
        perror("Failed to get wireless mode");
        return;
    }
    printf("Wireless mode: %d\n", wreq.u.mode);
    if (ioctl(sock, SIOCGIWFREQ, &wreq) == -1) { // get wireless frequency
        perror("Failed to get wireless frequency");
        return;
    }
    printf("Wireless frequency: %d\n", wreq.u.freq.m);
    if (ioctl(sock, SIOCGIWSENS, &wreq) == -1) { // get wireless sensitivity
        perror("Failed to get wireless sensitivity");
        return;
    }
    printf("Wireless sensitivity: %d\n", wreq.u.sens.value);
}

int main() {
    char ifname[IFNAMSIZ]; // interface name
    printf("Enter wireless interface name: ");
    if (fgets(ifname, IFNAMSIZ, stdin) == NULL) { // read interface name from user
        perror("Failed to read interface name");
        return 1;
    }
    if (strlen(ifname) > 0 && ifname[strlen(ifname) - 1] == '\n') {
        ifname[strlen(ifname) - 1] = '\0'; // remove trailing newline
    }
    print_wireless_info(ifname); // print wireless information
    return 0;
}