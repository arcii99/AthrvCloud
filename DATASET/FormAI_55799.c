//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/if_ether.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>

#define DEVICE "wlan0"

int main() {
    // Create socket
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        perror("Failed to create socket: ");
        exit(EXIT_FAILURE);
    }

    // Get network interface index
    struct ifreq if_idx;
    memset(&if_idx, 0, sizeof(if_idx));
    strncpy(if_idx.ifr_name, DEVICE, strlen(DEVICE));
    if (ioctl(sock_fd, SIOCGIFINDEX, &if_idx) < 0) {
        perror("Failed to get network interface index: ");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // Get wireless network information
    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, DEVICE, strlen(DEVICE));
    wrq.u.data.pointer = NULL;
    wrq.u.data.length = 0;
    wrq.u.data.flags = 0;
    if (ioctl(sock_fd, SIOCGIWSCAN, &wrq) < 0) {
        perror("Failed to get wireless network information: ");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // Parse wireless network information
    char *buffer = malloc(wrq.u.data.length);
    memcpy(buffer, wrq.u.data.pointer, wrq.u.data.length);
    free(wrq.u.data.pointer);

    int i = 0;
    while (i < wrq.u.data.length) {
        struct iw_event *event = (struct iw_event *) (buffer + i);
        printf("Event code: %d\n", event->cmd);

        switch (event->cmd) {
            case SIOCGIWESSID: {
                char essid[IW_ESSID_MAX_SIZE + 1] = {0};
                struct iw_point *essid_point = (struct iw_point *) (event + 1);
                memcpy(essid, essid_point->pointer, essid_point->length);
                printf("ESSID: %s\n", essid);
                break;
            }
            case SIOCGIWFREQ: {
                struct iw_freq *freq = (struct iw_freq *) (event + 1);
                printf("Frequency: %f GHz\n", (float) freq->m / 1000000000);
                break;
            }
            case SIOCGIWMODE: {
                __u32 mode = *(__u32 *) (event + 1);
                printf("Mode: %d\n", mode);
                break;
            }
            case SIOCGIWAP: {
                struct sockaddr *addr = (struct sockaddr *) (event + 1);
                char mac[18] = {0};
                sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X",
                        (unsigned char) addr->sa_data[0],
                        (unsigned char) addr->sa_data[1],
                        (unsigned char) addr->sa_data[2],
                        (unsigned char) addr->sa_data[3],
                        (unsigned char) addr->sa_data[4],
                        (unsigned char) addr->sa_data[5]);
                printf("AP MAC Address: %s\n", mac);
                break;
            }
        }

        i += event->len;
    }

    free(buffer);
    close(sock_fd);
    return 0;
}