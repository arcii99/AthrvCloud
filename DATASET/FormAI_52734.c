//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define MAX_INTERFACE_NAME_LEN 16

void analyze_signal_strength(char* interface) {
    int sock_fd; // socket file descriptor
    char if_name[MAX_INTERFACE_NAME_LEN];

    strncpy(if_name, interface, MAX_INTERFACE_NAME_LEN - 1);

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0); // create socket

    if(sock_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct iwreq request;
    strncpy(request.ifr_name, if_name, IFNAMSIZ);

    // get signal strength
    if(ioctl(sock_fd, SIOCGIWSTATS, &request) == -1) {
        perror("Failed to get signal strength");
        exit(1);
    }

    int signal_strength = request.u.qual.level;

    printf("The signal strength for %s is %d dBm\n", if_name, signal_strength);

    close(sock_fd);
}

int main(int argc, char** argv) {
    if(argc != 2) { // make sure interface is specified in command-line arguments
        printf("Usage: ./signal_strength [interface]\n");
        exit(1);
    }

    char* interface = argv[1];
    analyze_signal_strength(interface);

    return 0;
}