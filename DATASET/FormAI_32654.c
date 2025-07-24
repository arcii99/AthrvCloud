//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536
#define MAX_DEVICE_COUNT 255

struct wireless_device {
    char *ip_address;
    char *mac_address;
    char *hostname;
};

void scan_network(char *network) {
    int sockfd, status, count = 0;
    char packet[MAX_PACKET_SIZE];
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    struct wireless_device devices[MAX_DEVICE_COUNT];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return;
    }

    // set socket options to broadcast
    int broadcast_enabled = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast_enabled,
                   sizeof(broadcast_enabled)) == -1) {
        fprintf(stderr, "Error setting socket options: %s\n", strerror(errno));
        close(sockfd);
        return;
    }

    // create packet
    memset(packet, 0, MAX_PACKET_SIZE);
    snprintf(packet, MAX_PACKET_SIZE - 1, "WNS_REQUEST");

    // send packet to broadcast address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr(network);
    status = sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr *)&addr,
                    addrlen);
    if (status == -1) {
        fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
        close(sockfd);
        return;
    }

    // wait for responses
    while (1) {
        memset(packet, 0, MAX_PACKET_SIZE);
        status = recvfrom(sockfd, packet, MAX_PACKET_SIZE - 1, 0,
                          (struct sockaddr *)&addr, &addrlen);
        if (status == -1) {
            fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
            continue;
        } else if (status == 0) {
            continue;
        }

        // parse response
        char *str = strstr(packet, "WNS_REPLY");
        if (str == NULL) {
            continue;
        }
        char *ip_addr = inet_ntoa(addr.sin_addr);
        char *mac_addr = NULL;
        char *hostname = NULL;
        str = strtok(str + strlen("WNS_REPLY"), ",");
        while (str != NULL) {
            if (strncmp(str, "mac_address=", 12) == 0) {
                mac_addr = str + 12;
            } else if (strncmp(str, "hostname=", 9) == 0) {
                hostname = str + 9;
            }
            str = strtok(NULL, ",");
        }

        // add device to list
        if (mac_addr != NULL) {
            struct wireless_device *device = &devices[count++];
            device->ip_address = strdup(ip_addr);
            device->mac_address = strdup(mac_addr);
            if (hostname != NULL) {
                device->hostname = strdup(hostname);
            } else {
                device->hostname = strdup(ip_addr);
            }
        }

        // check if all devices have responded
        if (count >= MAX_DEVICE_COUNT) {
            break;
        }
    }

    // print devices
    printf("Wireless devices on network %s:\n", network);
    for (int i = 0; i < count; i++) {
        struct wireless_device *device = &devices[i];
        printf("  %s (%s) [%s]\n", device->hostname, device->ip_address,
               device->mac_address);
        free(device->ip_address);
        free(device->mac_address);
        free(device->hostname);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network>\n", argv[0]);
        return 1;
    }

    // scan network
    scan_network(argv[1]);

    return 0;
}