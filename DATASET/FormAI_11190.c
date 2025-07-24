//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <linux/wireless.h>

#define WIRELESS_INTERFACE_NAME  "wlan0"
#define AVERAGE_SIGNAL_STRENGTH_SAMPLE_WINDOW  5

volatile sig_atomic_t loop_condition = 1;

void signal_handler(int signal_number);

int main(int argc, char* argv[]) {
    if (getuid() != 0) {
        fprintf(stderr, "This program must be run as superuser\n");
        return EXIT_FAILURE;
    }

    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, WIRELESS_INTERFACE_NAME, IFNAMSIZ - 1);

    int socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_file_descriptor == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (ioctl(socket_file_descriptor, SIOCGIWNAME, &ifr) == -1) {
        fprintf(stderr, "The interface does not support wireless extensions\n");
        return EXIT_FAILURE;
    }

    struct iwreq iw;
    memset(&iw, 0, sizeof(iw));
    strncpy(iw.ifr_name, WIRELESS_INTERFACE_NAME, IFNAMSIZ - 1);

    while (loop_condition) {
        if (ioctl(socket_file_descriptor, SIOCGIWSCAN, &iw) == -1) {
            fprintf(stderr, "Error performing wireless scan: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        struct iw_range* iw_range = NULL;
        if (ioctl(socket_file_descriptor, SIOCGIWRANGE, &iw_range) == -1) {
            fprintf(stderr, "Error retrieving wireless range: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        int signal_strength_sum = 0;
        int sample_count = 0;
        struct iw_event* event = NULL;
        struct timeval last_event_time = { 0 };
        struct timeval current_time = { 0 };

        while ((event = (struct iw_event*) iw.u.data.pointer) != NULL) {
            gettimeofday(&current_time, NULL);
            if ((AVERAGE_SIGNAL_STRENGTH_SAMPLE_WINDOW * 1000) < (current_time.tv_sec - last_event_time.tv_sec + ((current_time.tv_usec - last_event_time.tv_usec) / 1000))) {
                break;
            }
            if (event->cmd == SIOCGIWAP) {
                memset(&ifr, 0, sizeof(ifr));
                strncpy(ifr.ifr_name, WIRELESS_INTERFACE_NAME, IFNAMSIZ - 1);
                memcpy(ifr.ifr_hwaddr.sa_data, event->u.ap_addr.sa_data, ETH_ALEN);
                strncpy(iw.u.essid.pointer, "", sizeof(""));
                if (ioctl(socket_file_descriptor, SIOCGIWESSID, &iw) == -1) {
                    strncpy(iw.u.essid.pointer, "<hidden>", sizeof("<hidden>"));
                }
                printf("Access Point with ESSID '%s' and MAC address %02x:%02x:%02x:%02x:%02x:%02x has signal strength %d dBm\n",
                    iw.u.essid.pointer, (unsigned char) ifr.ifr_hwaddr.sa_data[0], (unsigned char) ifr.ifr_hwaddr.sa_data[1],
                    (unsigned char) ifr.ifr_hwaddr.sa_data[2], (unsigned char) ifr.ifr_hwaddr.sa_data[3],
                    (unsigned char) ifr.ifr_hwaddr.sa_data[4], (unsigned char) ifr.ifr_hwaddr.sa_data[5], event->u.qual.level - iw_range->max_qual.level);
                signal_strength_sum += event->u.qual.level - iw_range->max_qual.level;
                ++sample_count;
            }
            iw.u.data.pointer += event->len;
            last_event_time = current_time;
        }

        if (sample_count > 0) {
            printf("Average signal strength over %d samples: %d dBm\n", sample_count, signal_strength_sum / sample_count);
        }
        sleep(1);
    }

    close(socket_file_descriptor);

    return EXIT_SUCCESS;
}

void signal_handler(int signal_number) {
    if (signal_number == SIGINT) {
        loop_condition = 0;
    }
}