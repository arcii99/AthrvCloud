//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

int main() {
    int sock;
    struct iwreq wrq;
    char* interface = "wlan0"; // Change this interface name according to your system
    char ssid[32];

    // Open socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set interface name
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);

    // Get SSID of available wireless networks
    wrq.u.data.pointer = NULL;
    wrq.u.data.length = 0;
    wrq.u.data.flags = 0;

    if (ioctl(sock, SIOCGIWSCAN, &wrq) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    struct iw_event iwe;
    char buffer[256];

    while (1) {
        // Read event
        if (read(sock, &iwe, sizeof(iwe)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Check for end of wireless scan
        if (iwe.cmd == SIOCGIWSCAN)
            break;

        // Get SSID
        if (iwe.cmd == IWEVGENIE) {
            memset(buffer, 0, sizeof(buffer));
            memcpy(buffer, iwe.u.data.pointer, iwe.u.data.length);
            if (strstr(buffer, "ESSID") != NULL) {
                memcpy(ssid, buffer + 6, iwe.u.data.length - 6);
                ssid[iwe.u.data.length - 6] = '\0';
                printf("%s\n", ssid);
            }
        }
    }

    close(sock);
    return 0;
}