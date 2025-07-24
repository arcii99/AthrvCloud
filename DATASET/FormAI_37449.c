//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define WIFI_INTERFACE "wlan0"

int main(void) {
    struct iwreq wi;
    int sockfd, iwstats;
    const char *essid;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Populate iwreq structure with interface name
    strncpy(wi.ifr_name, WIFI_INTERFACE, IFNAMSIZ - 1);

    printf("Scanning Wi-Fi networks...\n");
    // Scan for Wi-Fi networks
    iwstats = ioctl(sockfd, SIOCSIWSCAN, &wi);
    if (iwstats == -1) {
        perror("ioctl");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    sleep(2); // Wait for scanning to finish

    printf("Found networks:\n");

    // Get Wi-Fi statistics for each network
    iwstats = ioctl(sockfd, SIOCGIWSCAN, &wi);
    if (iwstats == -1) {
        perror("ioctl");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    struct iw_event iwe;
    char buf[4096];
    int buflen = 0;

    // Loop through buffer of Wi-Fi statistics
    while (buflen < sizeof(buf)) {
        if (read(sockfd, &iwe, sizeof(iwe)) != sizeof(iwe)) {
            break;
        }

        if (iwe.cmd == SIOCGIWAP) {
            // Access point address (MAC address)
            char mac_addr[6];
            memcpy(mac_addr, iwe.u.ap_addr.sa_data, 6);

            // Store human-readable ESSID for later
            essid = "(hidden)";
            struct iw_event iwe2;
            while (read(sockfd, &iwe2, sizeof(iwe2)) == sizeof(iwe2)) {
                if (iwe2.cmd == SIOCGIWESSID) {
                    int len = iwe2.u.data.length;
                    if (len > IW_ESSID_MAX_SIZE) len = IW_ESSID_MAX_SIZE;
                    memcpy(buf, iwe2.u.essid.pointer, len);
                    buf[len] = '\0';
                    essid = buf;
                    break;
                }
            }

            // Signal strength (Quality/Signal level in dBm)
            int signal_strength;
            if (iwe.u.qual.updated & IW_QUAL_QUAL_INVALID) {
                signal_strength = 0;
            } else if (iwe.u.qual.updated & IW_QUAL_DBM) {
                signal_strength = iwe.u.qual.level;
            } else if (iwe.u.qual.updated & IW_QUAL_RCPI) {
                signal_strength = (iwe.u.qual.level / 2) - 110;
            } else {
                signal_strength = 0;
            }

            // Print network information
            printf("[%02x:%02x:%02x:%02x:%02x:%02x] %3d dBm : %s\n",
                    mac_addr[0], mac_addr[1], mac_addr[2],
                    mac_addr[3], mac_addr[4], mac_addr[5],
                    signal_strength,
                    essid);
        }

        buflen += iwe.len;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}