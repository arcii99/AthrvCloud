//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <errno.h>

#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

int main() {
    int sockfd;
    struct ifreq ifr;

    // get socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Failed to open socket");
        exit(1);
    }

    // set interface to scanning mode
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ-1);
    ifr.ifr_flags |= (IFF_UP | IFF_RUNNING | IFF_PROMISC);
    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0) {
        perror("Failed to set interface to scanning mode");
        exit(1);
    }

    // scan for wireless networks
    printf("Scanning for wireless networks...\n");
    WiFiNetwork networks[10];
    int num_networks = 0;

    FILE* fp = popen("sudo iwlist wlan0 scan | grep 'ESSID\\|Signal level='", "r");
    if (fp == NULL) {
        perror("Failed to open iwlist scan");
        exit(1);
    }
    char line[256];
    char* token;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if ((token = strstr(line, "ESSID:\"")) != NULL) {
            token += strlen("ESSID:\"");
            char* end_quote = strstr(token, "\"");
            if (end_quote != NULL) {
                int ssid_length = end_quote - token;
                if (ssid_length > MAX_SSID_LENGTH) {
                    ssid_length = MAX_SSID_LENGTH;
                }
                strncpy(networks[num_networks].ssid, token, ssid_length);
                networks[num_networks].ssid[ssid_length] = '\0';
            }
        } else if ((token = strstr(line, "Signal level=")) != NULL) {
            int signal_strength;
            sscanf(token, "Signal level=%d dBm", &signal_strength);
            networks[num_networks].signal_strength = signal_strength;
            num_networks++;
        }
    }
    pclose(fp);

    // print out the networks
    printf("%d network(s) found:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("  %s (%d dBm)\n", networks[i].ssid, networks[i].signal_strength);
    }

    // close the socket
    close(sockfd);

    return 0;
}