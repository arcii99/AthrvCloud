//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <linux/wireless.h>

int main()
{
    printf("Welcome to the Wireless Network Scanner!\n\n");
    printf("Scanning for nearby wireless networks...\n");

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct iwreq iwreq;
    memset(&iwreq, 0, sizeof(iwreq));

    strncpy(iwreq.ifr_name, "wlan0", IFNAMSIZ);

    int iret = ioctl(sock, SIOCGIWNAME, &iwreq);
    if(iret < 0) {
        printf("Error: no wireless extensions!\n");
        return 1;
    }

    int skfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(skfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, "wlan0", IFNAMSIZ);
    wrq.u.data.pointer = NULL;
    wrq.u.data.length = 0;
    wrq.u.data.flags = 0;

    iret = ioctl(skfd, SIOCSIWSCAN, &wrq);
    if(iret < 0) {
        printf("Error scanning for wireless networks!\n");
        return 1;
    }

    printf("\n\n---Nearby Wireless Networks---\n");

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    wrq.u.data.pointer = buffer;
    wrq.u.data.length = sizeof(buffer);
    wrq.u.data.flags = 0;

    iret = ioctl(skfd, SIOCGIWSCAN, &wrq);
    if(iret < 0) {
        perror("Error retrieving wireless network list");
        return 1;
    }

    struct iw_event iwe;
    char *pos = buffer + sizeof(struct iwreq);

    for(; pos < buffer + iret; pos += iwe.len) 
    {
        memset(&iwe, 0, sizeof(iwe));
        memcpy(&iwe, pos, sizeof(iwe));

        if(iwe.cmd == SIOCGIWESSID) {
            char essid[32+1];
            memset(essid, 0, sizeof(essid));
            memcpy(essid, pos + iwe.len - 1, iwe.u.data.length);
            printf("\nESSID: %s\n", essid);
        }

        if(iwe.cmd == SIOCGIWFREQ) {
            int freq = iwe.u.freq.m;
            printf("Frequency: %d.%d GHz\n", freq / 1000000000, freq % 1000000000 / 100000000);
        }

        if(iwe.cmd == SIOCGIWAP) {
            struct sockaddr sa;
            memset(&sa, 0, sizeof(sa));
            memcpy(&sa, pos + iwe.len - sizeof(sa), sizeof(sa));
            char mac[32+1];
            memset(mac, 0, sizeof(mac));
            sprintf(mac, "%02x:%02x:%02x:%02x:%02x:%02x", sa.sa_data[0], sa.sa_data[1], sa.sa_data[2], sa.sa_data[3], sa.sa_data[4], sa.sa_data[5]);
            printf("MAC Address: %s\n", mac);
        }
    }

    close(sock);

    printf("\n\nDone scanning for wireless networks!\n");

    return 0;
}