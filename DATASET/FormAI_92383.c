//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>

// Define the maximum number of devices on the network
#define MAX_DEVICES 256

// Define the maximum length of a hostname
#define MAX_HOSTNAME_LENGTH 256

// Define the maximum length of an IP address string
#define MAX_IP_LENGTH INET_ADDRSTRLEN

// Define a structure to represent a device on the network
typedef struct {
    char hostname[MAX_HOSTNAME_LENGTH];
    char ip_address[MAX_IP_LENGTH];
} device_t;

// Function to get the list of IP addresses for the current machine's network interfaces
int get_ip_addresses(struct ifaddrs **ifaddr) {
    if (getifaddrs(ifaddr) == -1) {
        perror("getifaddrs");
        return -1;
    }

    return 0;
}

// Function to check if an IP address is valid
int is_valid_ip_address(const char *ip_address) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    return result != 0;
}

// Function to scan the network for devices
int scan_network(device_t *devices, int *num_devices) {
    char *subnet = "192.168.0"; // Change this to match your network subnet
    int port = 22; // We will use SSH as a test port

    int num_found = 0;

    for (int i = 1; i <= MAX_DEVICES; i++) {
        char ip_address[MAX_IP_LENGTH];
        snprintf(ip_address, MAX_IP_LENGTH, "%s.%d", subnet, i);
        if (!is_valid_ip_address(ip_address)) {
            // Skip invalid IP addresses
            continue;
        }

        struct sockaddr_in sa;
        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &(sa.sin_addr));

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            // Error creating socket
            perror("socket");
            return -1;
        }

        if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
            // Connected, so device is present on the network
            device_t device;
            strncpy(device.ip_address, ip_address, MAX_IP_LENGTH);
            struct hostent *host = gethostbyaddr(&(sa.sin_addr), sizeof(sa.sin_addr), AF_INET);
            if (host) {
                strncpy(device.hostname, host->h_name, MAX_HOSTNAME_LENGTH);
            } else {
                strncpy(device.hostname, ip_address, MAX_HOSTNAME_LENGTH);
            }
            devices[num_found++] = device;
        }

        close(sockfd);

        if (num_found >= MAX_DEVICES) {
            // We have reached the maximum number of devices to scan for
            break;
        }
    }

    *num_devices = num_found;

    return 0;
}

int main() {
    struct ifaddrs *ifaddr;
    if (get_ip_addresses(&ifaddr) == -1) {
        // Error getting IP addresses
        exit(EXIT_FAILURE);
    }

    printf("Scanning network...\n");

    device_t devices[MAX_DEVICES];
    int num_devices = 0;

    if (scan_network(devices, &num_devices) == -1) {
        // Error scanning network
        exit(EXIT_FAILURE);
    }

    printf("Found %d device(s) on the network:\n", num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s)\n", devices[i].hostname, devices[i].ip_address);
    }

    freeifaddrs(ifaddr);

    return 0;
}